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
    Object::ListType parents;
    parents.push_back(string("sight"));
    SetParents(parents);
}

Appearance Appearance::Instantiate()
{
    Appearance value;

    Object::ListType parents;
    parents.push_back(std::string("appearance"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
