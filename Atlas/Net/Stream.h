// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Michael Day, Dmitry Derevyanko, Stefanus Du Toit

#ifndef ATLAS_NET_STREAM_H
#define ATLAS_NET_STREAM_H

#include <iosfwd>
#include <string>
#include <list>

#include "../Negotiate.h"

namespace Atlas {

class Bridge;

namespace Net {

/** Negotiation of codecs for an Atlas connection

non blocking negotiation of Codecs
requires a list of avalable Codecs,
along with the name of sender and a Socket

@see Connection
@see Codec
*/

  class NegotiateHelper {

  public:

    NegotiateHelper(std::list<std::string> *names);

    bool get(std::string &buf, const std::string & header);
    void put(std::string &buf, const std::string & header);

  private:

    std::list<std::string> *names;

  };

class StreamConnect : public Atlas::Negotiate<std::iostream>
{
    public:

    StreamConnect(const std::string& name, std::iostream&, Atlas::Bridge*);

    virtual ~StreamConnect() {}

    virtual void Poll(bool can_read = true);

    virtual State GetState();
    virtual Atlas::Codec<std::iostream>* GetCodec();

    private:

    enum
    {
	SERVER_GREETING,
	CLIENT_GREETING,
	CLIENT_CODECS,
	SERVER_CODECS,
	DONE
    };

    int state;

    std::string outName;
    std::string inName;
    std::iostream& socket;
    Atlas::Bridge* bridge;
    std::list<std::string> inCodecs;
  
    NegotiateHelper codecHelper;
    std::string buf;

    void processServerCodecs();

    bool m_canPacked;
    bool m_canXml;
};
 
class StreamAccept : public Atlas::Negotiate<std::iostream>
{
    public:

    StreamAccept(const std::string& name, std::iostream&, Atlas::Bridge*);

    virtual ~StreamAccept() {}

    virtual void Poll(bool can_read = true);

    virtual State GetState();
    virtual Atlas::Codec<std::iostream>* GetCodec();

    private:

    enum
    {
	SERVER_GREETING,
	CLIENT_GREETING,
	CLIENT_CODECS,
	SERVER_CODECS,
	DONE
    };

    int state;

    std::string outName;
    std::string inName;
    std::iostream& socket;
    Atlas::Bridge* bridge;
    std::list<std::string> inCodecs;
  
    NegotiateHelper codecHelper;
    std::string buf;

    void processClientCodecs();

    bool m_canPacked;
    bool m_canXml;
};

} } // Atlas::Net

#endif

