// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_SMELL_H
#define ATLAS_OBJECTS_OPERATION_SMELL_H

#include <Atlas/Objects/Operation/Perception.h>


namespace Atlas { namespace Objects { namespace Operation { 

/** Character smells something

Base operator for all kind of perceptions

*/
class Smell : public Perception
{
public:
    /// Construct a Smell class definition.
    Smell();
  protected:
    Smell(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Smell();

    /// Create a new instance of Smell.
    static Smell Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_SMELL_H
