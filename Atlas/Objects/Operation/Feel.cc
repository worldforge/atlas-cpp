// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Feel.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Feel::Feel()
     : Perception()
{
    SetId(std::string("feel"));
    Object::ListType parents;
    parents.push_back(string("perception"));
    SetParents(parents);
}

Feel Feel::Instantiate()
{
    Feel value;

    Object::ListType parents;
    parents.push_back(std::string("feel"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
