// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#include "Bridge.h"
#include "Factory.h"

using namespace Atlas;

namespace Atlas {
    std::list<Factory::sClassInfo> Factory::aClassFactories;
}

Bridge::Map Bridge::MapBegin;
Bridge::List Bridge::ListBegin;
