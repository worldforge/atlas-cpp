// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_COMBINE_H
#define ATLAS_OBJECTS_OPERATION_COMBINE_H

#include <Atlas/Objects/Operation/Create.h>


namespace Atlas { namespace Objects { namespace Operation { 

/** Combine existing objects into new objects.

This is how normal characters create objects.

*/
class Combine : public Create
{
public:
    /// Construct a Combine class definition.
    Combine();
  protected:
    Combine(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Combine();

    /// Create a new instance of Combine.
    static Combine Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_COMBINE_H
