// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "AdminEntity.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

AdminEntity::AdminEntity()
     : RootEntity()
{
    SetId(std::string("admin_entity"));
    Object::ListType parents(1,std::string("root_entity"));
    SetParents(parents);
}

AdminEntity AdminEntity::Instantiate()
{
    AdminEntity value;

    value.SetParents(Object::ListType(1,std::string("admin_entity")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity
