// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Login.h"

using namespace std;
using namespace Atlas;
using namespace Atlas::Message;

namespace Atlas { namespace Objects { namespace Operation { 

Login::Login()
     : Get()
{
    SetAttr("id", string("login"));
    Object::ListType parent;
    parent.push_back(string("get"));
    SetAttr("parent", parent);
}

Login Login::Instantiate()
{
    Login login;

    Object::ListType parent;
    parent.push_back(string("login"));
    login.SetAttr("parent", parent);
    
    return login;
}

} } } // namespace Atlas::Objects::Operation
