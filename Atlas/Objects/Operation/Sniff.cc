// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Sniff.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Sniff::Sniff()
     : Perceive()
{
    SetId(std::string("sniff"));
    Object::ListType parents;
    parents.push_back(string("perceive"));
    SetParents(parents);
}

Sniff Sniff::Instantiate()
{
    Sniff value;

    Object::ListType parents;
    parents.push_back(std::string("sniff"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
