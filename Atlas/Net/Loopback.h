// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#ifndef ATLAS_NET_LOOPBACK_H
#define ATLAS_NET_LOOPBACK_H

namespace Atlas {

class Bridge;

namespace Net {

void Loopback(Bridge*, Bridge*, Bridge*&, Bridge*&);

} } // Atlas::Net namespace

#endif
