/**
 * @file ch09drill01.cpp
 * @date 2011-06-29
 *
 * testing a Date class
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
