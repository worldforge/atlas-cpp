// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Sound.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Sound::Sound()
     : Perception()
{
    SetId(std::string("sound"));
    Object::ListType parents(1,std::string("perception"));
    SetParents(parents);
}

Sound Sound::Instantiate()
{
    Sound value;

    value.SetParents(Object::ListType(1,std::string("sound")));
    value.SetObjtype(std::string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
