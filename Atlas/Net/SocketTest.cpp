/*
        SocketTest.cpp
        ----------------
        begin           : 1999.11.29
        copyright       : (C) 1999 by John Barrett (ZW)
        email           : jbarrett@box100.com
*/

#include "SocketTest.h"

static stest SocketTest("SocketTest");

int AppMain(int argc, char** argv)
{
	theApp->NewAppWin(0,"SocketTest",600,400, 0);

	return 0;	
}

//int WINAPI WinMain( 
//	HINSTANCE hInstance, 	  // handle to current instance 
//	HINSTANCE hPrevInstance,  // handle to previous instance 
//	LPSTR lpCmdLine,	  // pointer to command line 
//	int nCmdShow		  // show state of window 
//) {
//	main(0,NULL);
//}
 
vWindow* SocketTest::NewAppWin(
		vWindow* win, char* aname, int w, int h,
		vAppWinInfo* winInfo
) {
	vWindow*	awin = win;
	vAppWinInfo*	ainf = winInfo;
	char*		name = aname;

	//if (!awin) awin = new SockWindow(name,600,400);

	return vApp::NewAppWin(awin,name,600,400,ainf);
}



void execute()
{
	int res;

	Py_Initialize();

        ASocket* sock = new ATCPSocket();

	printf("NEW SOCK = %i\n", sock->getSock());

	res = sock->connect("www.worldforge.org", 80);
	printf("Connect = %i\n", res);

	res = sock->send("GET /\n\n");
	printf("send = %i\n", res);
	char	buf[1024];
	int	len;
	while ((len = sock->recv((char*)&buf,1023)) > 0)
	{
		buf[len] = 0;
		printf("%s", buf);
	}
	sock->close();
}


