// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_SOUND_H
#define ATLAS_OBJECTS_OPERATION_SOUND_H

#include "Perception.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** Character hears something

Base operator for all kind of perceptions

*/
class Sound : public Perception
{
public:
    /// Construct a Sound class definition.
    Sound();
  protected:
    Sound(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Sound() { }

    /// Create a new instance of Sound.
    static Sound Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_SOUND_H
