// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#include "RootEntity.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

RootEntity::RootEntity()
     : Root("root_entity", "root"), attr_stamp_contains(0.0)
{
    SetObjtype(std::string("class"));
    Object::ListType pos;
    pos.push_back(0.0);
    pos.push_back(0.0);
    pos.push_back(0.0);
    SetPos(pos);
    Object::ListType velocity;
    velocity.push_back(0.0);
    velocity.push_back(0.0);
    velocity.push_back(0.0);
    SetVelocity(velocity);
}

RootEntity::RootEntity(const string & id, const string & parent)
     : Root(id, parent), attr_stamp_contains(0.0)
{
    SetObjtype(std::string("class"));
    Object::ListType pos;
    pos.push_back(0.0);
    pos.push_back(0.0);
    pos.push_back(0.0);
    SetPos(pos);
    Object::ListType velocity;
    velocity.push_back(0.0);
    velocity.push_back(0.0);
    velocity.push_back(0.0);
    SetVelocity(velocity);
}

RootEntity RootEntity::Instantiate()
{
    RootEntity value;

    value.SetParents(Object::ListType(1,std::string("root_entity")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

bool RootEntity::HasAttr(const std::string& name) const
{
    if (name == "loc") return true;
    if (name == "pos") return true;
    if (name == "velocity") return true;
    if (name == "contains") return true;
    if (name == "stamp_contains") return true;
    return Root::HasAttr(name);
}

Object RootEntity::GetAttr(const std::string& name) const
    throw (NoSuchAttrException)
{
    if (name == "loc") return attr_loc;
    if (name == "pos") return attr_pos;
    if (name == "velocity") return attr_velocity;
    if (name == "contains") return attr_contains;
    if (name == "stamp_contains") return attr_stamp_contains;
    return Root::GetAttr(name);
}

void RootEntity::SetAttr(const std::string& name, const Object& attr)
{
    if (name == "loc") { SetLoc(attr.AsString()); return; }
    if (name == "pos") { SetPos(attr.AsList()); return; }
    if (name == "velocity") { SetVelocity(attr.AsList()); return; }
    if (name == "contains") { SetContains(attr.AsList()); return; }
    if (name == "stamp_contains") { SetStampContains(attr.AsFloat()); return; }
    Root::SetAttr(name, attr);
}

void RootEntity::RemoveAttr(const std::string& name)
{
    if (name == "loc") return;
    if (name == "pos") return;
    if (name == "velocity") return;
    if (name == "contains") return;
    if (name == "stamp_contains") return;
    Root::RemoveAttr(name);
}

void RootEntity::SendContents(Bridge* b) const
{
    SendLoc(b);
    SendPos(b);
    SendVelocity(b);
    SendContains(b);
    SendStampContains(b);
    Root::SendContents(b);
}

Object RootEntity::AsObject() const
{
    Object::MapType m = Root::AsObject().AsMap();
    m["loc"] = Object(attr_loc);
    m["pos"] = Object(attr_pos);
    m["velocity"] = Object(attr_velocity);
    m["contains"] = Object(attr_contains);
    m["stamp_contains"] = Object(attr_stamp_contains);
    return Object(m);
}

} } } // namespace Atlas::Objects::Entity

#include "AdminEntity.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

AdminEntity::AdminEntity()
     : RootEntity("admin_entity", "root_entity")
{
}

AdminEntity::AdminEntity(const string & id, const string & parent)
     : RootEntity(id, parent)
{
}

AdminEntity AdminEntity::Instantiate()
{
    AdminEntity value;

    value.SetParents(Object::ListType(1,std::string("admin_entity")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity

#include "Account.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Account::Account()
     : AdminEntity("account", "admin_entity")
{
}

Account::Account(const string & id, const string & parent)
     : AdminEntity(id, parent)
{
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

#include "Player.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Player::Player()
     : Account("player", "account")
{
}

Player::Player(const string & id, const string & parent)
     : Account(id, parent)
{
}

Player Player::Instantiate()
{
    Player value;

    value.SetParents(Object::ListType(1,std::string("player")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

bool Player::HasAttr(const std::string& name) const
{
    if (name == "characters") return true;
    return Account::HasAttr(name);
}

Object Player::GetAttr(const std::string& name) const
    throw (NoSuchAttrException)
{
    if (name == "characters") return attr_characters;
    return Account::GetAttr(name);
}

void Player::SetAttr(const std::string& name, const Object& attr)
{
    if (name == "characters") { SetCharacters(attr.AsList()); return; }
    Account::SetAttr(name, attr);
}

void Player::RemoveAttr(const std::string& name)
{
    if (name == "characters") return;
    Account::RemoveAttr(name);
}

void Player::SendContents(Bridge* b) const
{
    SendCharacters(b);
    Account::SendContents(b);
}

Object Player::AsObject() const
{
    Object::MapType m = Account::AsObject().AsMap();
    m["characters"] = Object(attr_characters);
    return Object(m);
}

} } } // namespace Atlas::Objects::Entity

#include "Admin.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Admin::Admin()
     : Account("admin", "account")
{
}

Admin::Admin(const string & id, const string & parent)
     : Account(id, parent)
{
}

Admin Admin::Instantiate()
{
    Admin value;

    value.SetParents(Object::ListType(1,std::string("admin")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity

#include "Game.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Game::Game()
     : AdminEntity("game", "admin_entity")
{
}

Game::Game(const string & id, const string & parent)
     : AdminEntity(id, parent)
{
}

Game Game::Instantiate()
{
    Game value;

    value.SetParents(Object::ListType(1,std::string("game")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity

#include "GameEntity.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

GameEntity::GameEntity()
     : RootEntity("game_entity", "root_entity")
{
}

GameEntity::GameEntity(const string & id, const string & parent)
     : RootEntity(id, parent)
{
}

GameEntity GameEntity::Instantiate()
{
    GameEntity value;

    value.SetParents(Object::ListType(1,std::string("game_entity")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity

