// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Divide.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Divide::Divide()
     : Create()
{
    SetId(std::string("divide"));
    Object::ListType parents(1,std::string("create"));
    SetParents(parents);
}

Divide Divide::Instantiate()
{
    Divide value;

    value.SetParents(Object::ListType(1,std::string("divide")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
