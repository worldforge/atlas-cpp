// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day, Dmitry Derevyanko

#ifndef ATLAS_NET_STREAM_H
#define ATLAS_NET_STREAM_H

#include <iosfwd>
#include <string>
#include <list>

#include "../Negotiate.h"

namespace Atlas { namespace Net {

/** Negotiation of codecs for an Atlas connection

non blocking negotiation of Codecs
requires a list of avalable Codecs,
along with the name of sender and a Socket

@see Connection
@see Codec
*/

  template <class T>
  class NegotiateHelper {

    typedef std::list<T*> Factories;

  public:

    NegotiateHelper(std::list<std::string> *names, Factories *out_factories);

    bool get(std::string &buf, std::string header);
    void put(std::string &buf, std::string header);

  private:

    std::list<std::string> *names;
    Factories *outFactories;

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
  
    typedef std::list<Atlas::Factory<Atlas::Codec<std::iostream> >*> FactoryCodecs;

    FactoryCodecs outCodecs;
    NegotiateHelper<Atlas::Factory<Atlas::Codec<std::iostream> > > codecHelper;
    std::string buf;

    void processServerCodecs();

    void processClientCodecs();
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
  
    typedef std::list<Atlas::Factory<Atlas::Codec<std::iostream> >*> FactoryCodecs;

    FactoryCodecs outCodecs;
    NegotiateHelper<Atlas::Factory<Atlas::Codec<std::iostream> > > codecHelper;
    std::string buf;

    void processServerCodecs();

    void processClientCodecs();
};

} } // Atlas::Net

#endif

