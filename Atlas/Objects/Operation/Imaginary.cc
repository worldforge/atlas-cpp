// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Imaginary.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Imaginary::Imaginary()
     : Action()
{
    SetId(std::string("imaginary"));
    Object::ListType parents;
    parents.push_back(string("action"));
    SetParents(parents);
}

Imaginary Imaginary::Instantiate()
{
    Imaginary value;

    Object::ListType parents;
    parents.push_back(std::string("imaginary"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
