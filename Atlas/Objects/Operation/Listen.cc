// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Listen.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Listen::Listen()
     : Perceive()
{
    SetId(std::string("listen"));
    Object::ListType parents;
    parents.push_back(std::string("perceive"));
    SetParents(parents);
}

Listen Listen::Instantiate()
{
    Listen value;

    Object::ListType parents;
    parents.push_back(std::string("listen"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
