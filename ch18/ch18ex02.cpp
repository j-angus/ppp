/**
 * @author Jason Angus
 * @file ch18ex02.cpp
 * @date 2011-09-11
 *
 * 2. Write a function, char* findx(const char* s, const char* x), that 
 *    finds the first occurrence of tile C-style string x in s. Do not use 
 *    any standard library functions. Do not use subscripting; use the 
 *    dereference operator * instead.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <climits> // for INT_MAX
#include <cstring>


void srcfile_info(); // display basic source file information
char* findx(const char* s, const char* x);
size_t my_strlen(const char* str);

int main()
{
	srcfile_info();
	const size_t max_size=1000;
	char str1[]="string1";
	char str2[]="g1";
	char* str3=new char[max_size];
	for (int i=0; i<(max_size); ++i) {
		str3[i]=62;
	}
	//str3[32000]='a'; // str3 not null terminated	
	cout << "my_strlen(str3): " << my_strlen(str3) << endl;
	cout << "INT_MAX: " << INT_MAX << endl;
	cout << "findx: " << findx(str1, str2) << "\n";
	
	return 0;
}

// return the length of a C-string (null terminated)
size_t my_strlen(const char* str)
{
	const char* s;
	for (s=str;*s;++s);
	return s-str;
}

// return the first occurrance of x in s
char* findx(const char* s, const char* x)
{
	const char* pos=s; // keep track of search progress through string s
	const char* c=x;

	cout << "We are looking for \"" << x << "\" in \"" << s 
		<< "\"\n";
	while (*s && *c) {
		if (*c==*s) {
			++c;
			++s;
		}
		else {
			++s;
			pos=s; // save our place in main string
			c=x; // reset to start of x	
		}
	}
	if (*s=='\0' && *c) {
		cout << "x not found.\n";
		pos=0; // x not found
	}
	return (char *)pos;
}

void srcfile_info() 
{
      cout << "File:\t\t" << __FILE__ << "\n"; 
      cout << "Compiled:\t" << __DATE__; 
      cout << " at " << __TIME__ << "\n\n"; return; 
}

