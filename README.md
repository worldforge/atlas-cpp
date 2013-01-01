#Atlas-C++

[DavidJFelix/atlas-cpp.git](https://github.com/DavidJFelix/atlas-cpp) Status:[![Build
Status](https://api.travis-ci.org/DavidJFelix/atlas-cpp.png)](http://travis-ci.org/DavidJFelix/atlas-cpp)

Welcome to Atlas-C++, the C++ reference implementation of the Atlas protocol.

NOTE!:
Many current programs use older version of Atlas-C++:
Use released version of Atlas-C++ for preference, unless you are working
with development code that requires this series.

This library implements the Atlas protocol, for use in client-server
game applications.  This library is suitable for linking to either
clients or servers.

##VERSION

This is Atlas-C++ 0.7.x, the latest development version of Atlas-C++. The
0.6.x branch will contain NO API CHANGES. The 0.7.x branch is completely
experimental and may not be easy to track. Any changes affecting the API
should go into 0.7.x, as should any features which are not completely
stable. 0.8.0 will be the next stable branch.

##SOCKET LIBRARIES

Atlas-C++ relies on iostreams being used as socket streams for network
communications. This means you will need to either use an existing library
or use your own.

One such a library is skstream, which you can download at:

ftp://ftp.worldforge.org/pub/worldforge/libs/skstream/

##DOCUMENTATION

To generate the documentation, simply configure the tree, then in Atlas-C++/
type "make docs". This will use doxygen to generate the documentation, which
will then reside in Atlas-C++/doc/.

Please read the file HACKING carefully before working on Atlas-C++.

##LICENSING

Atlas-C++ is licensed under the GNU Lesser General Public License. Please see
the file COPYING for details as to its distribution.

Atlas-C++ is provided AS IS with ABSOLUTELY NO WARRANTY. Please see the file
COPYING for details.

##CONTACT

Please see the AUTHORS file for contact information.
