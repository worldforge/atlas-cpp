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
    Object::ListType parents;
    parents.push_back(string("set"));
    SetParents(parents);
}

Move Move::Instantiate()
{
    Move value;

    Object::ListType parents;
    parents.push_back(std::string("move"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
