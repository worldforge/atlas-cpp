// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "GameEntity.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

GameEntity::GameEntity()
     : RootEntity()
{
    SetId(std::string("game_entity"));
    Object::ListType parents;
    parents.push_back(std::string("root_entity"));
    SetParents(parents);
}

GameEntity GameEntity::Instantiate()
{
    GameEntity value;

    Object::ListType parents;
    parents.push_back(std::string("game_entity"));
    value.SetParents(parents);
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity
