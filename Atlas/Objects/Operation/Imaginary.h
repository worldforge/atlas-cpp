// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_IMAGINARY_H
#define ATLAS_OBJECTS_OPERATION_IMAGINARY_H

#include "Action.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** When something is not yet implemented in server, then character can pretend to do something ;-)

This is base operation for all other
    operations and defines basic attributes. You can use this as
    starting point for browsing whole operation hiearchy. refno refers
    to operation this is reply for. In examples all attributes that
    are just as examples (and thus world specific) are started with 'e_'.

*/
class Imaginary : public Action
{
public:
    /// Construct a Imaginary class definition.
    Imaginary();
    /// Default destructor.
    virtual ~Imaginary() { }

    /// Create a new instance of Imaginary.
    static Imaginary Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_IMAGINARY_H
