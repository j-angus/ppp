/**
 * @author Jason Angus
 * @file ch18ex01.cpp
 * @date 2011-09-10
 *
 * 1. Write a function, char* strdup(const char*), that copies a C-style 
 *    string into memory it allocates on the free store. Do not use any 
 *    standard library functions. Do not use subscripting; use the 
 *    dereference operator * instead.  
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

//#include <vector>
//using std::vector;

void srcfile_info(); // display basic source file information

char* strdup(const char* str);

int main()
{
	srcfile_info();
	
	char str1[]="string1";
	cout << "str1: " << str1 << endl;
	cout << "copy of str1: " << strdup(str1) << endl;
	
	
	return 0;
}


char* strdup(const char* str)
{
	int len = 0;
//	char* p=str; // copy str so we can play with a pointer
	if (str)
		while (*str) { // test for end of str (NUL)
			++len; // increment str length
			++str; // move to next char
		}
	else
		return 0; // empty or NUL string

	char* dup = new char[len]; // create string storage on free store
	str-=len; // point to first char of str
	while (*str)
		*dup++=*str++; // copy from str to new string p
	*dup='\0'; // NUL terminate the string
	return dup-len;

}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

