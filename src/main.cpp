#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	try {
		// TODO do something
		
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

