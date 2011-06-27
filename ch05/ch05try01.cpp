/**
 * @file ch05try01.cpp
 * @date 2011-06-26
 *
 * test throwing an unhandled exception
 */


#include "../std_lib_facilities.h"

bool isint(string data);

int main()
{

	cout << "what happens when we throw an unhandled exception?\n";

	error("this is an error");

	return 0;
}
