// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Smell.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Smell::Smell()
     : Perception()
{
    SetId(std::string("smell"));
    Object::ListType parents;
    parents.push_back(string("perception"));
    SetParents(parents);
}

Smell Smell::Instantiate()
{
    Smell value;

    Object::ListType parents;
    parents.push_back(std::string("smell"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
