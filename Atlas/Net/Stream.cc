// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Michael Day, Dmitry Derevyanko, Stefanus Du Toit

// Note: this is obviously an awful hack, but for now it should work.
// All of this should be completely revised in Atlas-C++ 0.5.x.
// Please.
// The codecs are currently as hardcoded as they can be.

#include <iostream>

#include <Atlas/Codecs/XML.h>
#include <Atlas/Codecs/Packed.h>
#include <Atlas/Net/Stream.h>

#define Debug(prg) { if (debug_flag) { prg } }

static const bool debug_flag = false;

static std::string get_line(std::string &s, char ch)
{
  std::string out;
  int n = s.find(ch);
  if(n > 0) 
    {
      out.assign(s, 0, n);
      s.erase(0, n+1);
    }

  return out;
}

static inline std::string get_line(std::string &s1, char ch, std::string &s2)
{
  s2 = get_line(s1, ch);

  return s2;
}

Atlas::Net::NegotiateHelper::NegotiateHelper(std::list<std::string> *names) :
  names(names)
{ 
}

bool Atlas::Net::NegotiateHelper::get(std::string &buf, const std::string & header)
{
  std::string s, h;
  
  while(!buf.empty())
    {
      // check for end condition
      if(buf.find('\n') == 0)
	{
	  buf.erase(0, 1);
	  return true;
	}
	
      if(get_line(buf, '\n', s) == "")
	break;
	
      if(get_line(s, ' ', h) == header)
	{
	  names->push_back(s);
	    
	  Debug(std::cout << " got: " << s << std::endl;);
	}
      else
	Debug(std::cerr << "Unknown pattern " << h << std::endl;);
    }
  return false;
}

void Atlas::Net::NegotiateHelper::put(std::string &buf, const std::string & header)
{
  buf.erase();

  buf += header;
  buf += " Packed\n";

  buf += header;
  buf += " XML\n";

  buf += "\n";
}

Atlas::Net::StreamConnect::StreamConnect(const std::string& name, std::iostream& s,
Bridge* bridge) :
  state(SERVER_GREETING), outName(name), socket(s), bridge(bridge),
  codecHelper(&inCodecs), m_canPacked(true), m_canXml(true)
{
}

void Atlas::Net::StreamConnect::Poll(bool can_read)
{
    Debug(std::cout << "** Client(" << state << ") : " << std::endl;);

    std::string out;

    do
    {
	if (can_read || (socket.rdbuf()->in_avail() > 0)) buf += socket.get();

    if(state == SERVER_GREETING)
    {
	// get server greeting

	if (buf.size() > 0 && get_line(buf, '\n', inName) != "")
	{
	    Debug(std::cout << "server: " << inName << std::endl;);
	    state++;
	}
    }

    if(state == CLIENT_GREETING)
    {
	// send client greeting
	
	socket << "ATLAS " << outName << std::endl;
	state++;
    }
    
    if (state == CLIENT_CODECS)
    {
	codecHelper.put(out, "ICAN");
	socket << out << std::flush;
	state++;
    }

    if(state == SERVER_CODECS)
    {
	if (codecHelper.get(buf, "IWILL"))
	{
	    processServerCodecs();
	    state++;
	}
    }
    
    } while ((state != DONE) && (socket.rdbuf()->in_avail() > 0));
}

Atlas::Negotiate<std::iostream>::State Atlas::Net::StreamConnect::GetState()
{
    if (state == DONE)
    {
        if (m_canPacked || m_canXml)
        {
            return SUCCEEDED;
        }
    }
    else if (socket.good())
    {
	return IN_PROGRESS;
    }
    return FAILED;
}

Atlas::Codec<std::iostream>* Atlas::Net::StreamConnect::GetCodec()
{
    if (m_canPacked) return new Atlas::Codecs::Packed(socket, bridge);
    if (m_canXml) return new Atlas::Codecs::XML(socket, bridge);
    return NULL;
}


void Atlas::Net::StreamConnect::processServerCodecs()
{
    std::list<std::string>::iterator j;

    for (j = inCodecs.begin(); j != inCodecs.end(); ++j)
      {
        if (*j == "Packed") m_canPacked = true;
        if (*j == "XML") m_canXml = true;
      }

}
  
Atlas::Net::StreamAccept::StreamAccept(const std::string& name, std::iostream& s,
Bridge* bridge) :
  state(SERVER_GREETING), outName(name), socket(s), bridge(bridge),
  codecHelper(&inCodecs), m_canPacked(false), m_canXml(false)
{
}

void Atlas::Net::StreamAccept::Poll(bool can_read)
{
    Debug(std::cout << "** Server(" << state << ") : " << std::endl;);

    std::string out;

    if (state == SERVER_GREETING) 
    {
	// send server greeting

	socket << "ATLAS " << outName << std::endl;
	state++;
    }

    do
    {
	if (can_read || (socket.rdbuf()->in_avail() > 0)) buf += socket.get();

    if (state == CLIENT_GREETING)
    {
	// get client greeting
	
	if (buf.size() > 0 && get_line(buf, '\n', inName) != "")
        {
	    Debug(std::cout << "client: " << inName << std::endl;);
	    state++;
        }
    }
    
    if (state == CLIENT_CODECS)
    {
	if (codecHelper.get(buf, "ICAN"))
	{
	    state++;
	}
        processClientCodecs();
    }
    
    if (state == SERVER_CODECS)
    {
        if (m_canPacked) socket << "IWILL Packed\n";
        else if (m_canXml) socket << "IWILL XML\n";
        socket << std::endl;
        state++;
    }
    
    } while ((state != DONE) && (socket.rdbuf()->in_avail() > 0));
}

Atlas::Negotiate<std::iostream>::State Atlas::Net::StreamAccept::GetState()
{
    if (state == DONE)
    {
        if (m_canPacked || m_canXml)
        {
            return SUCCEEDED;
        }
    }
    else if (socket.good())
    {
	return IN_PROGRESS;
    }
    return FAILED;
}

Atlas::Codec<std::iostream>* Atlas::Net::StreamAccept::GetCodec()
{
    if (m_canPacked) return new Atlas::Codecs::Packed(socket, bridge);
    if (m_canXml) return new Atlas::Codecs::XML(socket, bridge);
    return NULL;
}

void Atlas::Net::StreamAccept::processClientCodecs()
{
    std::list<std::string>::iterator j;

    for (j = inCodecs.begin(); j != inCodecs.end(); ++j)
      {
        if (*j == "XML") m_canXml = true;
        if (*j == "Packed") m_canPacked = true;
      }
}
