// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Michael Day, Stefanus Du Toit

#ifndef ATLAS_CODECS_XML_H
#define ATLAS_CODECS_XML_H

#include <iostream>
#include <stack>

#include <Atlas/Codec.h>

namespace Atlas { namespace Codecs {

/*

Sample output for this codec: (whitespace added for clarity)

<atlas>
    <map>
	<int name="foo">13</int>
	<float name="meep">1.5</float>
	<string name="bar">hello</string>
	<list name="args">
	    <int>1</int>
	    <int>2</int>
	    <float>3.0</float>
	</list>
    </map>
</atlas>

The complete specification is located in cvs at:
    forge/protocols/atlas/spec/xml_syntax.html

*/

class XML : public Codec<std::iostream>
{
    public:

    XML(std::iostream& s, Atlas::Bridge* b);

    virtual void Poll(bool can_read = true);

    virtual void StreamBegin();
    virtual void StreamMessage(const Map&);
    virtual void StreamEnd();
    
    virtual void MapItem(const std::string& name, const Map&);
    virtual void MapItem(const std::string& name, const List&);
    virtual void MapItem(const std::string& name, long);
    virtual void MapItem(const std::string& name, double);
    virtual void MapItem(const std::string& name, const std::string&);
    virtual void MapEnd();
    
    virtual void ListItem(const Map&);
    virtual void ListItem(const List&);
    virtual void ListItem(double);
    virtual void ListItem(long);
    virtual void ListItem(const std::string&);
    virtual void ListEnd();

    protected:

    std::iostream& socket;
    Bridge* bridge;
    
    enum Token
    {
	TOKEN_TAG,
	TOKEN_START_TAG,
	TOKEN_END_TAG,
	TOKEN_DATA
    };
    
    Token token;
    
    enum State
    {
	PARSE_NOTHING,
	PARSE_STREAM,
        PARSE_MAP,
        PARSE_LIST,
	PARSE_INT,
	PARSE_FLOAT,
	PARSE_STRING
    };
    
    std::stack<State> state;
    std::stack<std::string> data;

    std::string tag;
    std::string name;

    inline void TokenTag(char);
    inline void TokenStartTag(char);
    inline void TokenEndTag(char);
    inline void TokenData(char);

    inline void ParseStartTag();
    inline void ParseEndTag();
};

} } // namespace Atlas::Codecs

#endif
