// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_ENTITY_ADMIN_H
#define ATLAS_OBJECTS_ENTITY_ADMIN_H

#include <Atlas/Objects/Entity/Account.h>


namespace Atlas { namespace Objects { namespace Entity { 

/** Privileged accounts

Later in hierarchy tree objtype changes to 'object' when actual game objects are made.

*/
class Admin : public Account
{
public:
    /// Construct a Admin class definition.
    Admin();
  protected:
    Admin(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Admin() { }

    /// Create a new instance of Admin.
    static Admin Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Entity

#endif // ATLAS_OBJECTS_ENTITY_ADMIN_H
