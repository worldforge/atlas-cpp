// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Appearance.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Appearance::Appearance()
     : Sight()
{
    SetId(std::string("appearance"));
    Object::ListType parents(1,std::string("sight"));
    SetParents(parents);
}

Appearance Appearance::Instantiate()
{
    Appearance value;

    value.SetParents(Object::ListType(1,std::string("appearance")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
