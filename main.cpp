#include <iostream>
#include <string>
#include "Server.h"

using namespace std;

int main(int argc,char*argv[])
{
	Server *server = new Server;
	server->Init();
	cout << "Geocool's HTTP Web Server " << AppVersion << endl;
	server->Start();

	return 0;
}