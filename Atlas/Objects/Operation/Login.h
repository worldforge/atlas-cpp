// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_LOGIN_H
#define ATLAS_OBJECTS_OPERATION_LOGIN_H

#include <Atlas/Objects/Operation/Get.h>


namespace Atlas { namespace Objects { namespace Operation { 

/** Operation for logging into server

For more about <a href="login.html">out of game atlas here</a>

*/
class Login : public Get
{
public:
    /// Construct a Login class definition.
    Login();
  protected:
    Login(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Login();

    /// Create a new instance of Login.
    static Login Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_LOGIN_H
