// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Combine.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Combine::Combine()
     : Create()
{
    SetId(std::string("combine"));
    Object::ListType parents(1,std::string("create"));
    SetParents(parents);
}

Combine Combine::Instantiate()
{
    Combine value;

    value.SetParents(Object::ListType(1,std::string("combine")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
