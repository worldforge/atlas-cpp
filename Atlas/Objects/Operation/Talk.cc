// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Talk.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Talk::Talk()
     : Communicate()
{
    SetId(std::string("talk"));
    Object::ListType parents(1,std::string("communicate"));
    SetParents(parents);
}

Talk Talk::Instantiate()
{
    Talk value;

    value.SetParents(Object::ListType(1,std::string("talk")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
