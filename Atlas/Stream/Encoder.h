// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#ifndef ATLAS_STREAM_ENCODER_H
#define ATLAS_STREAM_ENCODER_H

#include "Filter.h"
#include "../Object/Object.h"

// $Log$
// Revision 1.7  2000-02-21 05:23:10  mike
// Hmm but will it handle a *second* commit nicely?
//
// Revision 1.6  2000/02/21 05:22:11  mike
// Checking how this funky tag works
//

namespace Atlas
{
    namespace Stream
    {
	class Encoder;
    }
}

class Atlas::Stream::Encoder
{
    public:

    virtual ~Encoder() { }

    enum Container
    {
	LIST,
	MAP,
    };
    
    virtual void Begin(Container) = 0;
    virtual void Begin(const std::string& name, Container) = 0;
    
    virtual void End() = 0;
    
    virtual void Send(int) = 0;
    virtual void Send(float) = 0;
    virtual void Send(const std::string&) = 0;
    virtual void Send(const Object&) = 0;
	
    virtual void Send(const std::string& name, int) = 0;
    virtual void Send(const std::string& name, float) = 0;
    virtual void Send(const std::string& name, const std::string&) = 0;
    virtual void Send(const std::string& name, const Object&) = 0;
};

#endif
