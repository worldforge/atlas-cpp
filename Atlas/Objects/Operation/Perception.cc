// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Perception.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Perception::Perception()
     : Info()
{
    SetId(std::string("perception"));
    Object::ListType parents;
    parents.push_back(std::string("info"));
    SetParents(parents);
}

Perception Perception::Instantiate()
{
    Perception value;

    Object::ListType parents;
    parents.push_back(std::string("perception"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
