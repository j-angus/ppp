/**
 * @author Jason Angus
 * @file ch17tt3_1.cpp
 * @date 2011-08-15
 *
 * Try this exercise, 17.3.1, page 577
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;
using std::stringstream;

#include <vector>
using std::vector;

int main()
{
	cout << "ch17tt3_1.cpp\n\n";

	cout << "the size of char is: " << sizeof(char) <<' '<< sizeof('a') << endl;
	cout << "the size of int is: " << sizeof(int) <<' '<< sizeof(2+2) << endl;

	int* p=0;
	cout << "the size of int* is: " << sizeof(int*) <<' '<< sizeof(p) << endl;

	cout << "the size of bool is: " << sizeof(bool) <<' '<< sizeof(true) << endl;
	cout << "the size of double is: " << sizeof(double) <<' '<< sizeof(123.45) << endl;

return 0;
}