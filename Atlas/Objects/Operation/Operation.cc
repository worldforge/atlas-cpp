// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#include "RootOperation.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

RootOperation::RootOperation()
     : Root("root_operation", "root"), attr_serialno(0), attr_refno(0), attr_seconds(0.0), attr_future_seconds(0.0)
{
    SetObjtype(std::string("op_definition"));
}

RootOperation::RootOperation(const string & id, const string & parent)
     : Root(id, parent), attr_serialno(0), attr_refno(0), attr_seconds(0.0), attr_future_seconds(0.0)
{
    SetObjtype(std::string("op_definition"));
}

RootOperation RootOperation::Instantiate()
{
    RootOperation value;

    value.SetParents(Object::ListType(1,std::string("root_operation")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

bool RootOperation::HasAttr(const std::string& name) const
{
    if (name == "serialno") return true;
    if (name == "refno") return true;
    if (name == "from") return true;
    if (name == "to") return true;
    if (name == "seconds") return true;
    if (name == "future_seconds") return true;
    if (name == "time_string") return true;
    if (name == "args") return true;
    return Root::HasAttr(name);
}

Object RootOperation::GetAttr(const std::string& name) const
    throw (NoSuchAttrException)
{
    if (name == "serialno") return attr_serialno;
    if (name == "refno") return attr_refno;
    if (name == "from") return attr_from;
    if (name == "to") return attr_to;
    if (name == "seconds") return attr_seconds;
    if (name == "future_seconds") return attr_future_seconds;
    if (name == "time_string") return attr_time_string;
    if (name == "args") return attr_args;
    return Root::GetAttr(name);
}

void RootOperation::SetAttr(const std::string& name, const Object& attr)
{
    if (name == "serialno") { SetSerialno(attr.AsInt()); return; }
    if (name == "refno") { SetRefno(attr.AsInt()); return; }
    if (name == "from") { SetFrom(attr.AsString()); return; }
    if (name == "to") { SetTo(attr.AsString()); return; }
    if (name == "seconds") { SetSeconds(attr.AsFloat()); return; }
    if (name == "future_seconds") { SetFutureSeconds(attr.AsFloat()); return; }
    if (name == "time_string") { SetTimeString(attr.AsString()); return; }
    if (name == "args") { SetArgs(attr.AsList()); return; }
    Root::SetAttr(name, attr);
}

void RootOperation::RemoveAttr(const std::string& name)
{
    if (name == "serialno") return;
    if (name == "refno") return;
    if (name == "from") return;
    if (name == "to") return;
    if (name == "seconds") return;
    if (name == "future_seconds") return;
    if (name == "time_string") return;
    if (name == "args") return;
    Root::RemoveAttr(name);
}

void RootOperation::SendContents(Bridge* b) const
{
    SendSerialno(b);
    SendRefno(b);
    SendFrom(b);
    SendTo(b);
    SendSeconds(b);
    SendFutureSeconds(b);
    SendTimeString(b);
    SendArgs(b);
    Root::SendContents(b);
}

Object RootOperation::AsObject() const
{
    Object::MapType m = Root::AsObject().AsMap();
    m["serialno"] = Object(attr_serialno);
    m["refno"] = Object(attr_refno);
    m["from"] = Object(attr_from);
    m["to"] = Object(attr_to);
    m["seconds"] = Object(attr_seconds);
    m["future_seconds"] = Object(attr_future_seconds);
    m["time_string"] = Object(attr_time_string);
    m["args"] = Object(attr_args);
    return Object(m);
}

} } } // namespace Atlas::Objects::Operation

#include "Action.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Action::Action()
     : RootOperation("action", "root_operation")
{
}

Action::Action(const string & id, const string & parent)
     : RootOperation(id, parent)
{
}

Action Action::Instantiate()
{
    Action value;

    value.SetParents(Object::ListType(1,std::string("action")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Create.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Create::Create()
     : Action("create", "action")
{
}

Create::Create(const string & id, const string & parent)
     : Action(id, parent)
{
}

Create Create::Instantiate()
{
    Create value;

    value.SetParents(Object::ListType(1,std::string("create")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Combine.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Combine::Combine()
     : Create("combine", "create")
{
}

Combine::Combine(const string & id, const string & parent)
     : Create(id, parent)
{
}

Combine Combine::Instantiate()
{
    Combine value;

    value.SetParents(Object::ListType(1,std::string("combine")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Divide.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Divide::Divide()
     : Create("divide", "create")
{
}

Divide::Divide(const string & id, const string & parent)
     : Create(id, parent)
{
}

Divide Divide::Instantiate()
{
    Divide value;

    value.SetParents(Object::ListType(1,std::string("divide")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Communicate.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Communicate::Communicate()
     : Create("communicate", "create")
{
}

Communicate::Communicate(const string & id, const string & parent)
     : Create(id, parent)
{
}

Communicate Communicate::Instantiate()
{
    Communicate value;

    value.SetParents(Object::ListType(1,std::string("communicate")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Talk.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Talk::Talk()
     : Communicate("talk", "communicate")
{
}

Talk::Talk(const string & id, const string & parent)
     : Communicate(id, parent)
{
}

Talk Talk::Instantiate()
{
    Talk value;

    value.SetParents(Object::ListType(1,std::string("talk")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Delete.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Delete::Delete()
     : Action("delete", "action")
{
}

Delete::Delete(const string & id, const string & parent)
     : Action(id, parent)
{
}

Delete Delete::Instantiate()
{
    Delete value;

    value.SetParents(Object::ListType(1,std::string("delete")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Set.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Set::Set()
     : Action("set", "action")
{
}

Set::Set(const string & id, const string & parent)
     : Action(id, parent)
{
}

Set Set::Instantiate()
{
    Set value;

    value.SetParents(Object::ListType(1,std::string("set")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Move.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Move::Move()
     : Set("move", "set")
{
}

Move::Move(const string & id, const string & parent)
     : Set(id, parent)
{
}

Move Move::Instantiate()
{
    Move value;

    value.SetParents(Object::ListType(1,std::string("move")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Get.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Get::Get()
     : Action("get", "action")
{
}

Get::Get(const string & id, const string & parent)
     : Action(id, parent)
{
}

Get Get::Instantiate()
{
    Get value;

    value.SetParents(Object::ListType(1,std::string("get")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Perceive.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Perceive::Perceive()
     : Get("perceive", "get")
{
}

Perceive::Perceive(const string & id, const string & parent)
     : Get(id, parent)
{
}

Perceive Perceive::Instantiate()
{
    Perceive value;

    value.SetParents(Object::ListType(1,std::string("perceive")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Look.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Look::Look()
     : Perceive("look", "perceive")
{
}

Look::Look(const string & id, const string & parent)
     : Perceive(id, parent)
{
}

Look Look::Instantiate()
{
    Look value;

    value.SetParents(Object::ListType(1,std::string("look")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Listen.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Listen::Listen()
     : Perceive("listen", "perceive")
{
}

Listen::Listen(const string & id, const string & parent)
     : Perceive(id, parent)
{
}

Listen Listen::Instantiate()
{
    Listen value;

    value.SetParents(Object::ListType(1,std::string("listen")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Sniff.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Sniff::Sniff()
     : Perceive("sniff", "perceive")
{
}

Sniff::Sniff(const string & id, const string & parent)
     : Perceive(id, parent)
{
}

Sniff Sniff::Instantiate()
{
    Sniff value;

    value.SetParents(Object::ListType(1,std::string("sniff")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Touch.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Touch::Touch()
     : Perceive("touch", "perceive")
{
}

Touch::Touch(const string & id, const string & parent)
     : Perceive(id, parent)
{
}

Touch Touch::Instantiate()
{
    Touch value;

    value.SetParents(Object::ListType(1,std::string("touch")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Login.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Login::Login()
     : Get("login", "get")
{
}

Login::Login(const string & id, const string & parent)
     : Get(id, parent)
{
}

Login Login::Instantiate()
{
    Login value;

    value.SetParents(Object::ListType(1,std::string("login")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Logout.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Logout::Logout()
     : Login("logout", "login")
{
}

Logout::Logout(const string & id, const string & parent)
     : Login(id, parent)
{
}

Logout Logout::Instantiate()
{
    Logout value;

    value.SetParents(Object::ListType(1,std::string("logout")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Imaginary.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Imaginary::Imaginary()
     : Action("imaginary", "action")
{
}

Imaginary::Imaginary(const string & id, const string & parent)
     : Action(id, parent)
{
}

Imaginary Imaginary::Instantiate()
{
    Imaginary value;

    value.SetParents(Object::ListType(1,std::string("imaginary")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Info.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Info::Info()
     : RootOperation("info", "root_operation")
{
}

Info::Info(const string & id, const string & parent)
     : RootOperation(id, parent)
{
}

Info Info::Instantiate()
{
    Info value;

    value.SetParents(Object::ListType(1,std::string("info")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Perception.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Perception::Perception()
     : Info("perception", "info")
{
}

Perception::Perception(const string & id, const string & parent)
     : Info(id, parent)
{
}

Perception Perception::Instantiate()
{
    Perception value;

    value.SetParents(Object::ListType(1,std::string("perception")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Sight.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Sight::Sight()
     : Perception("sight", "perception")
{
}

Sight::Sight(const string & id, const string & parent)
     : Perception(id, parent)
{
}

Sight Sight::Instantiate()
{
    Sight value;

    value.SetParents(Object::ListType(1,std::string("sight")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Appearance.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Appearance::Appearance()
     : Sight("appearance", "sight")
{
}

Appearance::Appearance(const string & id, const string & parent)
     : Sight(id, parent)
{
}

Appearance Appearance::Instantiate()
{
    Appearance value;

    value.SetParents(Object::ListType(1,std::string("appearance")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Disappearance.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Disappearance::Disappearance()
     : Sight("disappearance", "sight")
{
}

Disappearance::Disappearance(const string & id, const string & parent)
     : Sight(id, parent)
{
}

Disappearance Disappearance::Instantiate()
{
    Disappearance value;

    value.SetParents(Object::ListType(1,std::string("disappearance")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Sound.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Sound::Sound()
     : Perception("sound", "perception")
{
}

Sound::Sound(const string & id, const string & parent)
     : Perception(id, parent)
{
}

Sound Sound::Instantiate()
{
    Sound value;

    value.SetParents(Object::ListType(1,std::string("sound")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Smell.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Smell::Smell()
     : Perception("smell", "perception")
{
}

Smell::Smell(const string & id, const string & parent)
     : Perception(id, parent)
{
}

Smell Smell::Instantiate()
{
    Smell value;

    value.SetParents(Object::ListType(1,std::string("smell")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Feel.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Feel::Feel()
     : Perception("feel", "perception")
{
}

Feel::Feel(const string & id, const string & parent)
     : Perception(id, parent)
{
}

Feel Feel::Instantiate()
{
    Feel value;

    value.SetParents(Object::ListType(1,std::string("feel")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

#include "Error.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Error::Error()
     : Info("error", "info")
{
}

Error::Error(const string & id, const string & parent)
     : Info(id, parent)
{
}

Error Error::Instantiate()
{
    Error value;

    value.SetParents(Object::ListType(1,std::string("error")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation

