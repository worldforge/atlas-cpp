// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Account.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Account::Account()
     : AdminEntity()
{
    SetId(std::string("account"));
    Object::ListType parents(1,std::string("admin_entity"));
    SetParents(parents);
    SetPassword(std::string(""));
}

Account Account::Instantiate()
{
    Account value;

    value.SetParents(Object::ListType(1,std::string("account")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

bool Account::HasAttr(const std::string& name) const
{
    if (name == "password") return true;
    return AdminEntity::HasAttr(name);
}

Object Account::GetAttr(const std::string& name) const
    throw (NoSuchAttrException)
{
    if (name == "password") return attr_password;
    return AdminEntity::GetAttr(name);
}

void Account::SetAttr(const std::string& name, const Object& attr)
{
    if (name == "password") { SetPassword(attr.AsString()); return; }
    AdminEntity::SetAttr(name, attr);
}

void Account::RemoveAttr(const std::string& name)
{
    if (name == "password") return;
    AdminEntity::RemoveAttr(name);
}

void Account::SendContents(Bridge* b) const
{
    SendPassword(b);
    AdminEntity::SendContents(b);
}

Object Account::AsObject() const
{
    Object::MapType m = AdminEntity::AsObject().AsMap();
    m["password"] = Object(attr_password);
    return Object(m);
}

} } } // namespace Atlas::Objects::Entity
