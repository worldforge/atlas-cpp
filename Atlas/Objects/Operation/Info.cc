// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Info.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Info::Info()
     : RootOperation()
{
    SetId(std::string("info"));
    Object::ListType parents(1,std::string("root_operation"));
    SetParents(parents);
}

Info Info::Instantiate()
{
    Info value;

    value.SetParents(Object::ListType(1,std::string("info")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
