// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Perceive.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Perceive::Perceive()
     : Get()
{
    SetId(std::string("perceive"));
    Object::ListType parents;
    parents.push_back(std::string("get"));
    SetParents(parents);
}

Perceive Perceive::Instantiate()
{
    Perceive value;

    Object::ListType parents;
    parents.push_back(std::string("perceive"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
