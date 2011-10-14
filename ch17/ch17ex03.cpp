/**
 * @author Jason Angus
 * @file ch17ex02.cpp
 * @date 2011-08-26
 *
 * 3. Write a function, void to_lower(char* s), that replaces all uppercase
 * characters in the C-style string s with their lowercase equivalents.
 * For example, "Hello, World! " becomes "hello, world!"
 * Do not use any standard library functions. A C-style string is a
 * zero-tenninated array of characters, so if you find a char with the
 * value 0 you are at the end.
 */

// #include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void srcfile_info(); // display basic source file information

// convert c-style string to lower-case
void to_lower(char* s);

int main()
{
	srcfile_info();

	char str[] = "AZ1230Cc0321az";

	cout << "str: " << str <<endl;
	to_lower(str);
	cout << "str: " << str <<endl;

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}

void to_lower(char* s)
{
	while (*s) {
		//cout << "*s: " << (int)*s << endl;
		if (*s>='A' && *s<='Z') {
			//cout << "*s is uppercase: " << *s <<endl;
			//cout << "a - A: " << 'a'-'A' << endl;
			*s+='a'-'A'; // conversion
			//cout << "*s lower: " << *s << endl;
		}
		++s; // next char
	}

	return;
}