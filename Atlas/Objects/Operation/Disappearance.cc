// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Disappearance.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Disappearance::Disappearance()
     : Sight()
{
    SetId(std::string("disappearance"));
    Object::ListType parents(1,std::string("sight"));
    SetParents(parents);
}

Disappearance Disappearance::Instantiate()
{
    Disappearance value;

    value.SetParents(Object::ListType(1,std::string("disappearance")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
