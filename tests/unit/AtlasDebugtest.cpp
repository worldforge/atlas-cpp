// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2006 Alistair Riddoch

#ifdef NDEBUG
#undef NDEBUG
#endif

#ifndef DEBUG
#define DEBUG
#endif

#include <Atlas/Debug.h>

#include <cassert>

static bool debug_flag = true;

int main()
{
    bool flag_set = false;

    ATLAS_DEBUG(flag_set = true;)
    assert(flag_set == true);

    debug_flag = false;

    ATLAS_DEBUG(flag_set = false;)
    assert(flag_set == true);

}
