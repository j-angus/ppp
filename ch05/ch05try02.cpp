/**
 * @file ch05try02.cpp
 * @date 2011-06-26
 *
 * test throwing and handling a runtime error
 */


#include "../std_lib_facilities.h"

bool isint(string data);

int main()
{

try {
	cout << "what happens when we throw an unhandled exception?\n";

	error("this is an error");
}
catch (runtime_error& e) {
	cerr << "runtime error: " << e.what() << endl;

	return 1;
}
	return 0;
}
