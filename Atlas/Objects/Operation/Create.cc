// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Create.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Create::Create()
     : Action()
{
    SetId(std::string("create"));
    Object::ListType parents(1,std::string("action"));
    SetParents(parents);
}

Create Create::Instantiate()
{
    Create value;

    value.SetParents(Object::ListType(1,std::string("create")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
