// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Sound.h"

using namespace std;
using namespace Atlas;
using namespace Atlas::Message;

namespace Atlas { namespace Objects { namespace Operation { 

Sound::Sound()
     : Perception()
{
    SetAttr("id", string("sound"));
    Object::ListType parent;
    parent.push_back(string("perception"));
    SetAttr("parent", parent);
}

Sound Sound::Instantiate()
{
    Sound sound;

    Object::ListType parent;
    parent.push_back(string("sound"));
    sound.SetAttr("parent", parent);
    
    return sound;
}

} } } // namespace Atlas::Objects::Operation
