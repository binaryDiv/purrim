#include <iostream>
#include "JabberHandler.h"

using namespace std;

int main(int argc, char** argv) {
	try {
		// TODO do something
		
		JabberHandler jabber;
		
		jabber.connect("user@server.tld", "password");
		
		return 0;
	}
	catch (const char* msg) {
		cerr << "Exception caught in main: " << msg << endl;
		return 1;
	}
	catch (...) {
		cerr << "Unknown exception caught in main." << endl;
		return 1;
	}
}

