// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_FEEL_H
#define ATLAS_OBJECTS_OPERATION_FEEL_H

#include <Atlas/Objects/Operation/Perception.h>


namespace Atlas { namespace Objects { namespace Operation { 

/** Character feels something (with fingers usually)

Base operator for all kind of perceptions

*/
class Feel : public Perception
{
public:
    /// Construct a Feel class definition.
    Feel();
  protected:
    Feel(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Feel() { }

    /// Create a new instance of Feel.
    static Feel Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_FEEL_H
