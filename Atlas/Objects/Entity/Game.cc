// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Game.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Game::Game()
     : AdminEntity()
{
    SetId(std::string("game"));
    Object::ListType parents;
    parents.push_back(std::string("admin_entity"));
    SetParents(parents);
}

Game Game::Instantiate()
{
    Game value;

    Object::ListType parents;
    parents.push_back(std::string("game"));
    value.SetParents(parents);
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity
