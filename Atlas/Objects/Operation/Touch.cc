// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Touch.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Touch::Touch()
     : Perceive()
{
    SetId(std::string("touch"));
    Object::ListType parents(1,std::string("perceive"));
    SetParents(parents);
}

Touch Touch::Instantiate()
{
    Touch value;

    value.SetParents(Object::ListType(1,std::string("touch")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
