// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Admin.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Admin::Admin()
     : Account()
{
    SetId(std::string("admin"));
    Object::ListType parents(1,std::string("account"));
    SetParents(parents);
}

Admin Admin::Instantiate()
{
    Admin value;

    value.SetParents(Object::ListType(1,std::string("admin")));
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity
