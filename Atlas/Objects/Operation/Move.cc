// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Move.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Move::Move()
     : Set()
{
    SetId(std::string("move"));
    Object::ListType parents(1,std::string("set"));
    SetParents(parents);
}

Move Move::Instantiate()
{
    Move value;

    value.SetParents(Object::ListType(1,std::string("move")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
