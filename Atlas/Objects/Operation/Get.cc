// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Get.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Get::Get()
     : Action()
{
    SetId(std::string("get"));
    Object::ListType parents(1,std::string("action"));
    SetParents(parents);
}

Get Get::Instantiate()
{
    Get value;

    value.SetParents(Object::ListType(1,std::string("get")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
