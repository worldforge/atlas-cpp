// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Stefanus Du Toit

#ifndef ATLAS_OBJECTS_DECODER_H
#define ATLAS_OBJECTS_DECODER_H

#include <Atlas/Message/DecoderBase.h>

#include <Atlas/Objects/Root.h>
#include <Atlas/Objects/Entity/Account.h>
#include <Atlas/Objects/Entity/Admin.h>
#include <Atlas/Objects/Entity/AdminEntity.h>
#include <Atlas/Objects/Entity/Game.h>
#include <Atlas/Objects/Entity/Player.h>
#include <Atlas/Objects/Entity/RootEntity.h>
#include <Atlas/Objects/Operation/Action.h>
#include <Atlas/Objects/Operation/Appearance.h>
#include <Atlas/Objects/Operation/Combine.h>
#include <Atlas/Objects/Operation/Communicate.h>
#include <Atlas/Objects/Operation/Create.h>
#include <Atlas/Objects/Operation/Delete.h>
#include <Atlas/Objects/Operation/Disappearance.h>
#include <Atlas/Objects/Operation/Divide.h>
#include <Atlas/Objects/Operation/Error.h>
#include <Atlas/Objects/Operation/Feel.h>
#include <Atlas/Objects/Operation/Get.h>
#include <Atlas/Objects/Operation/Imaginary.h>
#include <Atlas/Objects/Operation/Info.h>
#include <Atlas/Objects/Operation/Listen.h>
#include <Atlas/Objects/Operation/Login.h>
#include <Atlas/Objects/Operation/Logout.h>
#include <Atlas/Objects/Operation/Look.h>
#include <Atlas/Objects/Operation/Move.h>
#include <Atlas/Objects/Operation/Perceive.h>
#include <Atlas/Objects/Operation/Perception.h>
#include <Atlas/Objects/Operation/RootOperation.h>
#include <Atlas/Objects/Operation/Set.h>
#include <Atlas/Objects/Operation/Sight.h>
#include <Atlas/Objects/Operation/Smell.h>
#include <Atlas/Objects/Operation/Sniff.h>
#include <Atlas/Objects/Operation/Sound.h>
#include <Atlas/Objects/Operation/Talk.h>
#include <Atlas/Objects/Operation/Touch.h>

namespace Atlas { namespace Objects {

/** Objects hierarchy decoder
 *
 * This decoder can be bound to a codec, will assemble incoming messages,
 * check their type, convert them into the appropriate instance in the
 * Objects hierarchy and call the relevant member functions, which
 * subclasses can conveniently override to pick up the object.
 *
 * @see Atlas::Objects::Encoder
 * @author Stefanus Du Toit <sdt@gmx.net>
 */
class Decoder : public Atlas::Message::DecoderBase
{
public:
    /// Default destructor.
    virtual ~Decoder();

protected:
    /// Overridden by Objects::Decoder to retrieve the object.
    virtual void ObjectArrived(const Atlas::Message::Object&);

    /// An unknown object has arrived.
    virtual void UnknownObjectArrived(const Atlas::Message::Object&) { }

    /// A Root object has arrived.
    virtual void ObjectArrived(const Root&) { }

    virtual void ObjectArrived(const Entity::Account&) { }
    virtual void ObjectArrived(const Entity::Admin&) { }
    virtual void ObjectArrived(const Entity::AdminEntity&) { }
    virtual void ObjectArrived(const Entity::Game&) { }
    virtual void ObjectArrived(const Entity::Player&) { }
    virtual void ObjectArrived(const Entity::RootEntity&) { }

    virtual void ObjectArrived(const Operation::Action&) { }
    virtual void ObjectArrived(const Operation::Appearance&) { }
    virtual void ObjectArrived(const Operation::Combine&) { }
    virtual void ObjectArrived(const Operation::Communicate&) { }
    virtual void ObjectArrived(const Operation::Create&) { }
    virtual void ObjectArrived(const Operation::Delete&) { }
    virtual void ObjectArrived(const Operation::Disappearance&) { }
    virtual void ObjectArrived(const Operation::Divide&) { }
    virtual void ObjectArrived(const Operation::Error&) { }
    virtual void ObjectArrived(const Operation::Feel&) { }
    virtual void ObjectArrived(const Operation::Get&) { }
    virtual void ObjectArrived(const Operation::Imaginary&) { }
    virtual void ObjectArrived(const Operation::Info&) { }
    virtual void ObjectArrived(const Operation::Listen&) { }
    virtual void ObjectArrived(const Operation::Login&) { }
    virtual void ObjectArrived(const Operation::Logout&) { }
    virtual void ObjectArrived(const Operation::Look&) { }
    virtual void ObjectArrived(const Operation::Move&) { }
    virtual void ObjectArrived(const Operation::Perceive&) { }
    virtual void ObjectArrived(const Operation::Perception&) { }
    virtual void ObjectArrived(const Operation::RootOperation&) { }
    virtual void ObjectArrived(const Operation::Set&) { }
    virtual void ObjectArrived(const Operation::Sight&) { }
    virtual void ObjectArrived(const Operation::Smell&) { }
    virtual void ObjectArrived(const Operation::Sniff&) { }
    virtual void ObjectArrived(const Operation::Sound&) { }
    virtual void ObjectArrived(const Operation::Talk&) { }
    virtual void ObjectArrived(const Operation::Touch&) { }
    
};

} } // namespace Atlas::Objects
#endif
