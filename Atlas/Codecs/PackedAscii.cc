// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Stefanus Du Toit

#include "../Stream/Codec.h"
#include "Utility.h"

#include <stack>

using namespace std;
using namespace Atlas::Stream;

/*

[type][name]=[data][|endtype]
  
{} for message
() for lists
[] for maps
$ for string
@ for int
# for float

*/

class PackedAscii : public Codec
{
public:
    
    PackedAscii(const Codec::Parameters&);

    virtual void Poll();

    virtual void MessageBegin();
    virtual void MessageMapBegin();
    virtual void MessageEnd();
    
    virtual void MapItem(const std::string& name, const Map&);
    virtual void MapItem(const std::string& name, const List&);
    virtual void MapItem(const std::string& name, int);
    virtual void MapItem(const std::string& name, double);
    virtual void MapItem(const std::string& name, const std::string&);
    virtual void MapEnd();
    
    virtual void ListItem(const Map&);
    virtual void ListItem(const List&);
    virtual void ListItem(int);
    virtual void ListItem(double);
    virtual void ListItem(const std::string&);
    virtual void ListEnd();

protected:
    
    iostream& socket;
    Filter* filter;
    Bridge* bridge;

    enum parsestate_t {
        PARSE_MSG,
        PARSE_MAP,
        PARSE_LIST,
        PARSE_INT,
        PARSE_FLOAT,
        PARSE_STRING,
        PARSE_NAME,
        PARSE_ASSIGN,
        PARSE_VALUE
    };
    
    stack<parsestate_t> parseStack;
    stack<string> fragments;
    string currentFragment;
};

namespace
{
    Codec::Factory<PackedAscii> factory("PackedAscii", Codec::Metrics(1, 2));
}

PackedAscii::PackedAscii(const Codec::Parameters& p) :
    socket(p.stream), filter(p.filter), bridge(p.bridge)
{
}

void mapItem(Bridge* b, parsestate_t type, const string& name,
        const string& value)
{
    switch (type) {
        case PARSE_STRING : b->MapItem(name, value);
                            break;
        case PARSE_INT: b->MapItem(name, atoi(value.c_str()));
                        break;
        case PARSE_FLOAT: b->MapItem(name, atof(value.c_str()));
                          break;
    }
}

void listItem(Bridge* b, parsestate_t type, const string& value)
{
    switch (type) {
        case PARSE_STRING : b->ListItem(value);
                            break;
        case PARSE_INT: b->ListItem(atoi(value.c_str()));
                        break;
        case PARSE_FLOAT: b->ListItem(atof(value.c_str()));
                          break;
    }
}

void popStack(stack<parsestate_t>& parseStack, stack<string>& fragments,
        Bridge* b)
{
    // FIXME
    // check for right stack entries (VALUE, ASSIGN, NAME)
    // depending on what comes before that, add to the bridge, pop off nicely

    string name, value;
    parsestate_t type;
    
    if (parseStack.top() != PARSE_VALUE) return; // FIXME report error
    parseStack.pop();
    value = fragments.pop();
    if (parseStack.top() != PARSE_ASSIGN) return; // FIXME report error
    parseStack.pop();
    if (parseStack.top() != PARSE_NAME) return; // FIXME report error
    parseStack.pop();
    name = fragments.pop();
    
    type = parseStack.pop();
    
    switch (parseStack.top()) {
        case PARSE_MAP: mapItem(b, type, name, value);
                        break;
        case PARSE_LIST: listItem(b, type, value);
                         break;
        default: break; // FIXME report error
    }
}

void PackedAscii::Poll() // muchas FIXME
{
    if (!socket.rdbuf()->in_avail()) return; // no data waiting

    // FIXME
    // what about dehexifying?
    // basically, we should look at everything in the stream
    // if we find '+' plus 2 chars, dehexify and put back?
    // maybe...
    
    char next = socket.get(); // get character
    
    switch (next) {
        case '{':
	    if (parseStack.empty())
	    {
		bridge->MessageBegin();
                parseStack.push(PARSE_MSG);
	    }
        break;
	
        case '}':
	    // FIXME handle empty stack or incorrect nesting
	    if (parseStack.top() == PARSE_MSG)
	    {
		bridge->MessageEnd();
		parseStack.pop();
	    }
	break;
	
        case '[':
	    // FIXME ensure that this map is in the right context
	    if (parseStack.top() == PARSE_MSG)
	    {
		bridge->MessageBeginMap();
	    }
	    else if (parseStack.top() == PARSE_MAP)
	    {
		// FIXME need the map name
		// so this needs to be handled by fragments some how
		bridge->MapItem("", MapBegin);
	    }
	    else if (parseStack.top() == PARSE_LIST)
	    {
		bridge->ListItem(MapBegin);
	    }
		
	    parseStack.push(PARSE_MAP);
        break;
	
        case ']': popStack(parseStack, fragments, bridge);
                  parseStack.pop(); // PARSE_MAP
                  break; // FIXME
        case '(': parseStack.push(PARSE_LIST);
                  break; // FIXME
        case ')': popStack(parseStack, fragments, bridge);
                  parseStack.pop(); // PARSE_LIST
                  break; // FIXME
        case '$': break; // FIXME
        case '@': break; // FIXME
        case '#': break; // FIXME
    }
    // FIXME - finish this
    // do whatever with it depending on the stack
    // possibly pop off the stack
}

void PackedAscii::MessageBegin()
{
    socket << "{";
}

void PackedAscii::MessageMapBegin()
{
    socket << "[=";
}

void PackedAscii::MessageEnd()
{
    socket << "}";
}

void PackedAscii::MapItem(const std::string& name, const Map&)
{
    socket << "[" << hexEncode("+", "+{}[]()@#$=", name) << "=";
}

void PackedAscii::MapItem(const std::string& name, const List&)
{
    socket << "(" << hexEncode("+", "+{}[]()@#$=", name) << "=";
}

void PackedAscii::MapItem(const std::string& name, int data)
{
    socket << "@" << hexEncode("+", "+{}[]()@#$=", name) << "=" << data;
}

void PackedAscii::MapItem(const std::string& name, double data)
{
    socket << "#" << hexEncode("+", "+{}[]()@#$=", name) << "=" << data;
}

void PackedAscii::MapItem(const std::string& name, const std::string& data)
{
    socket << "$" << hexEncode("+", "+{}[]()@#$=", name) << "=" <<
            hexEncode("+", "+{}[]()@#$=", data);
}

void PackedAscii::MapEnd()
{
    socket << "]";
}

void PackedAscii::ListItem(const Map&)
{
    socket << "[=";
}

void PackedAscii::ListItem(const List&)
{
    socket << "(=";
}

void PackedAscii::ListItem(int data)
{
    socket << "@=" << data;
}

void PackedAscii::ListItem(double data)
{
    socket << "#=" << data;
}

void PackedAscii::ListItem(const std::string& data)
{
    socket << "$=" << hexEncode("+", "+{}[]()@#$=", data);
}

void PackedAscii::ListEnd()
{
    socket << ")";
}