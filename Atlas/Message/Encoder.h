// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Stefanus Du Toit

#ifndef ATLAS_MESSAGE_ENCODER_H
#define ATLAS_MESSAGE_ENCODER_H

#include <Atlas/EncoderBase.h>

namespace Atlas { namespace Message {

class Object;

/** Encoder that transmits Atlas::Message::Object.
 *
 * This encoder can be used to send Atlas::Message::Object objects representing
 * full atlas messages.
 *
 * @see Object
 * @see Atlas::Bridge
 * @see Atlas::EncoderBase
 * @author Stefanus Du Toit <sdt@gmx.net>
 */
class Encoder : public Atlas::EncoderBase
{
public:
    Encoder(Atlas::Bridge*);

    virtual ~Encoder() { }

    /// Ensure that methods in base class are not hidden
    virtual void StreamMessage(const Map& m)
    { EncoderBase::StreamMessage(m); }

    virtual void MapItem(const std::string& name, const Bridge::Map& m)
    { EncoderBase::MapItem(name, m); }
    virtual void MapItem(const std::string& name, const Bridge::List& l)
    { EncoderBase::MapItem(name, l); }
    virtual void MapItem(const std::string& name, long i)
    { EncoderBase::MapItem(name, i); }
    virtual void MapItem(const std::string& name, double d)
    { EncoderBase::MapItem(name, d); }
    virtual void MapItem(const std::string& name, const std::string& s)
    { EncoderBase::MapItem(name, s); }

    virtual void ListItem(const Bridge::Map& m) { EncoderBase::ListItem(m); }
    virtual void ListItem(const Bridge::List& l) { EncoderBase::ListItem(l); }
    virtual void ListItem(long i) { EncoderBase::ListItem(i); }
    virtual void ListItem(double d) { EncoderBase::ListItem(d); }
    virtual void ListItem(const std::string& s) { EncoderBase::ListItem(s); }

    /// Send a message (must be a map!) in stream state.
    virtual void StreamMessage(const Object& obj);

    /// Send an object as a map item.
    virtual void MapItem(const std::string&, const Object&);
    /// Send an object as a list item.
    virtual void ListItem(const Object&);
};

} } // namespace Atlas::Message

#endif


