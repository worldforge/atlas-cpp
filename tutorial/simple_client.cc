/* Simple Atlas-C++ Client
 *
 * Part of the Atlas-C++ Tutorial
 *
 * Copyright 2000 Stefanus Du Toit.
 *
 * This file is covered by the GNU Free Documentation License.
 */

#include <iostream>
#include <sockinet.h>
#include <Atlas/Bridge.h>
#include <Atlas/Negotiate.h>
#include <Atlas/Net/Stream.h>
#include "DebugBridge.h"

using namespace Atlas;
using namespace std;

void helloWorld(Codec<iostream>& c)
{
    c.StreamMessage(Bridge::MapBegin);
    c.MapItem("hello", "world");
    c.MapEnd();
}

int main(int argc, char** argv)
{
    iosockinet stream(sockbuf::sock_stream);

    stream->connect("127.0.0.1", 6767);
    
    DebugBridge d;
    Net::StreamConnect conn("simple_client", stream, &d);

    cout << "Negotiating... " << flush;
    
    while (conn.GetState() == Negotiate<iostream>::IN_PROGRESS) {
        conn.Poll();
    }

    cout << "done" << endl;

    if (conn.GetState() == Negotiate<iostream>::FAILED) {
        cerr << "Failed to negotiate" << endl;
        return 2;
    }

    Codec<iostream>* codec = conn.GetCodec();

    return 0;
}