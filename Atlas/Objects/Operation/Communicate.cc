// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Communicate.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Communicate::Communicate()
     : Create()
{
    SetId(std::string("communicate"));
    Object::ListType parents(1,std::string("create"));
    SetParents(parents);
}

Communicate Communicate::Instantiate()
{
    Communicate value;

    value.SetParents(Object::ListType(1,std::string("communicate")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
