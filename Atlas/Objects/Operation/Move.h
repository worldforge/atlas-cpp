// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_MOVE_H
#define ATLAS_OBJECTS_OPERATION_MOVE_H

#include <Atlas/Objects/Operation/Set.h>


namespace Atlas { namespace Objects { namespace Operation { 

/** Change position

More about <a href="move.html">movement here</a>

*/
class Move : public Set
{
public:
    /// Construct a Move class definition.
    Move();
  protected:
    Move(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Move();

    /// Create a new instance of Move.
    static Move Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_MOVE_H
