/**
 * @author Jason Angus
 * @file ch18ex02.cpp
 * @date 2011-09-12
 *
 * 3. Write a function, int strcmp(const char* s1, const char* s2), that 
 *   compares C-style strings. Let it return a negative number if s1 is 
 *   lexicographically before s2, zero if s1 equals s2, and a positive 
 *   number if s1 is lexicographically after s2. Do not use any standard 
 *   library functions. Do not use subscripting; use the dereference 
 *   operator * instead.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <climits> // for INT_MAX
#include <cstring>


void srcfile_info(); // display basic source file information
int my_strcmp(const char* s1, const char* s2);
size_t my_strlen(const char* str);

int main()
{
	srcfile_info();
	
	const char s1[]="zanger";
	const char s2[]="bank";

	cout << "my_strcmp(" << s1 << ", " << s2 << "): " 
		<< my_strcmp(s1,s2) << endl;

	return 0;
}

// return the length of a C-string (null terminated)
size_t my_strlen(const char* str)
{
	const char* s;
	for (s=str;*s;++s);
	return s-str;
}

// return lexicographical difference between s1 and s2
int my_strcmp(const char* s1, const char* s2)
{
	while (*s1 && *s2) {
		if (*s1==*s2) {
			++s1;
			++s2;
		}
		else
			break;
	}
	return *s1-*s2;
}

void srcfile_info() 
{
      cout << "File:\t\t" << __FILE__ << "\n"; 
      cout << "Compiled:\t" << __DATE__; 
      cout << " at " << __TIME__ << "\n\n"; return; 
}

