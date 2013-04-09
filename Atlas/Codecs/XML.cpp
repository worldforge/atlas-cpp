// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Michael Day, Stefanus Du Toit

// $Id$

#include <Atlas/Codecs/XML.h>

#include <iostream>

#include <cstdlib>

namespace Atlas { namespace Codecs {
    
XML::XML(std::iostream& s, Atlas::Bridge & b)
    : m_socket(s), m_bridge(b)
{
    m_token = TOKEN_DATA;
    m_state.push(PARSE_NOTHING);
    m_data.push("");
}

void XML::tokenTag(char next)
{
    m_tag.erase();
    
    switch (next)
    {
	case '/':
	    m_token = TOKEN_END_TAG;
	break;
	
	case '>':
	    // FIXME signal error here
	    // unexpected character
	break;
	
	default:
	    m_token = TOKEN_START_TAG;
	    m_tag += next;
	break;
    }
}

void XML::tokenStartTag(char next)
{
    switch (next)
    {
	case '<':
	    // FIXME signal error here
	    // unexpected character
	break;

	case '>':
	    parseStartTag();
	    m_token = TOKEN_DATA;
	    m_data.push("");
	break;

	default:
	    m_tag += next;
	break;
    }
}

void XML::tokenEndTag(char next)
{
    switch (next)
    {
	case '<':
	    // FIXME signal error here
	    // unexpected character
	break;

	case '>':
	    parseEndTag();
	    m_token = TOKEN_DATA;
	    m_data.pop();
	break;

	default:
	    m_tag += next;
	break;
    }
}

void XML::tokenData(char next)
{
    switch (next)
    {
	case '<':
	    m_token = TOKEN_TAG;
	break;

	case '>':
	    // FIXME signal error here
	    // unexpected character
	break;

	default:
	    m_data.top() += next;
	break;
    }
}

void XML::parseStartTag()
{
    int tag_end = (int) m_tag.find(' ');
    int name_start = (int) m_tag.find("name=\"") + 6;
    int name_end = (int) m_tag.rfind("\"");
    
    if (name_start < name_end)
    {
	m_name = unescape(std::string(m_tag, (unsigned long) name_start, (unsigned long) (name_end - name_start)));
    }
    else
    {
	m_name.erase();
    }
    
    m_tag = std::string(m_tag, 0, (unsigned long) tag_end);

    switch (m_state.top())
    {
	case PARSE_NOTHING:
	    if (m_tag == "atlas")
	    {
		m_bridge.streamBegin();
		m_state.push(PARSE_STREAM);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
	case PARSE_STREAM:
	    if (m_tag == "map")
	    {
		m_bridge.streamMessage();
		m_state.push(PARSE_MAP);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_MAP:
	    if (m_tag == "map")
	    {
		m_bridge.mapMapItem(m_name);
		m_state.push(PARSE_MAP);
	    }
	    else if (m_tag == "list")
	    {
		m_bridge.mapListItem(m_name);
		m_state.push(PARSE_LIST);
	    }
	    else if (m_tag == "int")
	    {
		m_state.push(PARSE_INT);
	    }
	    else if (m_tag == "float")
	    {
		m_state.push(PARSE_FLOAT);
	    }
	    else if (m_tag == "string")
	    {
		m_state.push(PARSE_STRING);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_LIST:
	    if (m_tag == "map")
	    {
		m_bridge.listMapItem();
		m_state.push(PARSE_MAP);
	    }
	    else if (m_tag == "list")
	    {
		m_bridge.listListItem();
		m_state.push(PARSE_LIST);
	    }
	    else if (m_tag == "int")
	    {
		m_state.push(PARSE_INT);
	    }
	    else if (m_tag == "float")
	    {
		m_state.push(PARSE_FLOAT);
	    }
	    else if (m_tag == "string")
	    {
		m_state.push(PARSE_STRING);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_INT:
	case PARSE_FLOAT:
	case PARSE_STRING:
	    // FIXME signal error here
	    // unexpected tag
	break;
    }
}

void XML::parseEndTag()
{
    switch (m_state.top())
    {
	case PARSE_NOTHING:
	    // FIXME signal error here
	    // unexpected tag
	break;
	
	case PARSE_STREAM:
	    if (m_tag == "atlas")
	    {
		m_bridge.streamEnd();
		m_state.pop();
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_MAP:
	    if (m_tag == "map")
	    {
		m_bridge.mapEnd();
		m_state.pop();
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_LIST:
	    if (m_tag == "list")
	    {
		m_bridge.listEnd();
		m_state.pop();
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_INT:
	    if (m_tag == "int")
	    {
		m_state.pop();
		if (m_state.top() == PARSE_MAP)
		{
		    m_bridge.mapIntItem(m_name, atol(m_data.top().c_str()));
		}
		else
		{
		    m_bridge.listIntItem(atol(m_data.top().c_str()));
		}
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_FLOAT:
	    if (m_tag == "float")
	    {
		m_state.pop();
		if (m_state.top() == PARSE_MAP)
		{
		    m_bridge.mapFloatItem(m_name, atof(m_data.top().c_str()));
		}
		else
		{
		    m_bridge.listFloatItem(atof(m_data.top().c_str()));
		}
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_STRING:
	    if (m_tag == "string")
	    {
		m_state.pop();
		if (m_state.top() == PARSE_MAP)
		{
		    m_bridge.mapStringItem(m_name, unescape(m_data.top()));
		}
		else
		{
		    m_bridge.listStringItem(unescape(m_data.top()));
		}
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
    }
}

void XML::poll(bool can_read)
{
    if (!can_read) return;

    m_socket.peek();

    std::streamsize count;

    while ((count = m_socket.rdbuf()->in_avail()) > 0) {

        for (int i = 0; i < count; ++i) {

	    int next = m_socket.rdbuf()->sbumpc();

	    switch (m_token)
	    {
	        case TOKEN_TAG:		    tokenTag(next); break;
	        case TOKEN_START_TAG:	    tokenStartTag(next); break;
	        case TOKEN_END_TAG:	    tokenEndTag(next); break;
	        case TOKEN_DATA:	    tokenData(next); break;
	    }
        }
    }
}

void XML::streamBegin()
{
    m_socket << "<atlas>";
}

void XML::streamEnd()
{
    m_socket << "</atlas>";
}

void XML::streamMessage()
{
    m_socket << "<map>";
}

void XML::mapMapItem(const std::string& name)
{
    m_socket << "<map name=\"" << escape(name) << "\">";
}

void XML::mapListItem(const std::string& name)
{
    m_socket << "<list name=\"" << escape(name) << "\">";
}

void XML::mapIntItem(const std::string& name, long data)
{
    m_socket << "<int name=\"" << escape(name) << "\">" << data << "</int>";
}

void XML::mapFloatItem(const std::string& name, double data)
{
    m_socket << "<float name=\"" << escape(name) << "\">" << data << "</float>";
}

void XML::mapStringItem(const std::string& name, const std::string& data)
{
    m_socket << "<string name=\"" << escape(name) << "\">" << escape(data) << "</string>";
}

void XML::mapEnd()
{
    m_socket << "</map>";
}

void XML::listMapItem()
{
    m_socket << "<map>";
}

void XML::listListItem()
{
    m_socket << "<list>";
}

void XML::listIntItem(long data)
{
    m_socket << "<int>" << data << "</int>";
}

void XML::listFloatItem(double data)
{
    m_socket << "<float>" << data << "</float>";
}

void XML::listStringItem(const std::string& data)
{
    m_socket << "<string>" << escape(data) << "</string>";
}

void XML::listEnd()
{
    m_socket << "</list>";
}

std::string XML::escape(const std::string& original)
{
    std::string buffer;
    buffer.reserve(original.size());
    for (size_t pos = 0; pos != original.size(); ++pos) {
        switch (original[pos]) {
        case '&':
            buffer.append("&amp;");
            break;
        case '\"':
            buffer.append("&quot;");
            break;
        case '\'':
            buffer.append("&apos;");
            break;
        case '<':
            buffer.append("&lt;");
            break;
        case '>':
            buffer.append("&gt;");
            break;
        default:
            buffer.append(1, original[pos]);
            break;
        }
    }
    return buffer;
}

std::string XML::unescape(const std::string& original)
{
    std::string buffer;
    buffer.reserve(original.size());
    for (size_t pos = 0; pos != original.size(); ++pos) {
        if (original[pos] == '&') {
            if (original.size() - pos >= 3) {
                if (original[pos+1] == 'l' && original[pos+2] == 't' && original[pos+3] == ';') {
                    buffer.append(1, '<');
                    pos += 3;
                    continue;
                } else if (original[pos+1] == 'g' && original[pos+2] == 't' && original[pos+3] == ';') {
                    buffer.append(1, '>');
                    pos += 3;
                    continue;
                }
            }
            if (original.size() - pos >= 4) {
                if (original[pos+1] == 'a' && original[pos+2] == 'm' && original[pos+3] == 'p' && original[pos+4] == ';') {
                    buffer.append(1, '&');
                    pos += 4;
                    continue;
                }
            }
            if (original.size() - pos >= 5) {
                if (original[pos+1] == 'q' && original[pos+2] == 'u' && original[pos+3] == 'o' && original[pos+4] == 't' && original[pos+5] == ';') {
                    buffer.append(1, '"');
                    pos += 5;
                    continue;
                } else if (original[pos+1] == 'a' && original[pos+2] == 'p' && original[pos+3] == 'o' && original[pos+4] == 's' && original[pos+5] == ';') {
                    buffer.append(1, '\'');
                    pos += 5;
                    continue;
                }
            }
        }
        buffer.append(1, original[pos]);
    }
    return buffer;
}


} } //namespace Atlas::Codecs
