// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Look.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Look::Look()
     : Perceive()
{
    SetId(std::string("look"));
    Object::ListType parents;
    parents.push_back(std::string("perceive"));
    SetParents(parents);
}

Look Look::Instantiate()
{
    Look value;

    Object::ListType parents;
    parents.push_back(std::string("look"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
