// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Stefanus Du Toit, Michael Day

#ifndef ATLAS_CODECS_PACKED_H
#define ATLAS_CODECS_PACKED_H

#include <iostream>
#include <string>
#include <stack>

#include "Utility.h"
#include "../Codec.h"

namespace Atlas { namespace Codecs {

/*

The form for each element of this codec is as follows:

[type][name=][data][|endtype]
  
( ) for lists
[ ] for maps
$ for string
@ for int
# for float

Sample output for this codec: (whitespace added for clarity)

[@id=17$name=Fred +28the +2b great+29#weight=1.5(args=@1@2@3)]

The complete specification is located in cvs at:
    forge/protocols/atlas/spec/packed_syntax.html
    
*/
  
class Packed : public Codec<std::iostream>
{
public:
    
    Packed(std::iostream& s, Atlas::Bridge* b);

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
    virtual void ListItem(long);
    virtual void ListItem(double);
    virtual void ListItem(const std::string&);
    virtual void ListEnd();

protected:
    
    std::iostream& socket;
    Bridge* bridge;

    enum State
    {
	PARSE_STREAM,
        PARSE_MAP,
        PARSE_LIST,
	PARSE_MAP_BEGIN,
	PARSE_LIST_BEGIN,
        PARSE_INT,
        PARSE_FLOAT,
        PARSE_STRING,
        PARSE_NAME,
    };
    
    std::stack<State> state;

    std::string name;
    std::string data;

    inline void ParseStream(char);
    inline void ParseMap(char);
    inline void ParseList(char);
    inline void ParseMapBegin(char);
    inline void ParseListBegin(char);
    inline void ParseInt(char);
    inline void ParseFloat(char);
    inline void ParseString(char);
    inline void ParseName(char);

    inline const string HexEncode(const std::string& data)
    {
	return hexEncode("+", "+[]()@#$=", data);
    }

    inline const string HexDecode(const std::string& data)
    {
	return hexDecode("+", data);
    }
};

} } // namespace Atlas::Codecs

#endif
