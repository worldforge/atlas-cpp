// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_ENTITY_ADMINENTITY_H
#define ATLAS_OBJECTS_ENTITY_ADMINENTITY_H

#include <Atlas/Objects/Entity/RootEntity.h>


namespace Atlas { namespace Objects { namespace Entity { 

/** All classes and objects used for adminitrativive purposes

Later in hierarchy tree objtype changes to 'object' when actual game objects are made.

*/
class AdminEntity : public RootEntity
{
public:
    /// Construct a AdminEntity class definition.
    AdminEntity();
  protected:
    AdminEntity(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~AdminEntity() { }

    /// Create a new instance of AdminEntity.
    static AdminEntity Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Entity

#endif // ATLAS_OBJECTS_ENTITY_ADMINENTITY_H
