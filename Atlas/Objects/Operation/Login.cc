// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Login.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Login::Login()
     : Get()
{
    SetId(std::string("login"));
    Object::ListType parents;
    parents.push_back(std::string("get"));
    SetParents(parents);
}

Login Login::Instantiate()
{
    Login value;

    Object::ListType parents;
    parents.push_back(std::string("login"));
    value.SetParents(parents);
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
