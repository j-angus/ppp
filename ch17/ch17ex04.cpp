/**
 * @author Jason Angus
 * @file ch17ex04.cpp
 * @date 2011-08-27
 *
 * 4. Write a function, char* strdup(const char* s), that copies a C-style
 *    string into memory it allocates on the free store. Do not use any standard
 *    library functions.
 */

// #include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void srcfile_info(); // display basic source file information

// copy a c-style string to a new memory location
char* strdup(const char* s);

int main()
{
	srcfile_info();

	char str[] = "AZ1\0";
	char* str2;

	cout << "str: " << str <<endl;
	str2 = strdup(str);
	cout << "str2: " << str2 <<endl;

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}

char* strdup(const char* s)
{
	const size_t SIZE_T_MAX = 4; // find compiler definition for max value of size_t
	size_t len = 0; // length of s
	bool str_term = true;

	// calculate length of s (look for '\0' termination char)
	for (size_t i=0; i<SIZE_T_MAX; ++i)
		if (s[i])
			++len;
		else
			break;
	cout << "DEBUG: strdup(), len: " << len << endl;
	// check that s is properly null terminated
	if (len == SIZE_T_MAX)
		if (s[SIZE_T_MAX]) // string s too long and not null terminated
			str_term = false;
	cout << "DEBUG: strdup(), str_term: " << (str_term ? "true" : "false") << endl;
	// allocate memory to copy s to
	char* str_dup = new char[len];

	// copy string s to str_dup
	for (size_t i=0; i<len; ++i)
		str_dup[i]=s[i];
	if (!str_term) // null terminate string if required
		str_dup[len]='\0';

	return str_dup;
}
