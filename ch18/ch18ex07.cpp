/**
 * @author Jason Angus
 * @file ch18ex07.cpp
 * @date 2011-09-16
 *
 * 
 * 7. Write versions of the cat_dot()s from the previous exercises to take 
 *    C-style strings as arguments and return a free-store-allocated C-style 
 *    string as the result. Do not use standard library functions or types in 
 *    the implementation. Test these functions with several strings. Be sure to 
 *    free (using delele) all tile memory you allocated from free Store (using 
 *    new). Compare the effort involved in this exercise with the effort 
 *    involved for exercises 5 and 6.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


void srcfile_info(); // display basic source file information

char* my_strdup(const char* str);
char* my_strstr(const char* s, const char* x);
int my_strcmp(const char* s1, const char* s2);
char* cat_dot(const char* s1, const char* s2);

int main()
{
	srcfile_info();
	const int len=8;

	char str1[len]; // test string, not nul terminated
	for (int i=0; i<len;++i)
		str1[i]='a';
	char str2[]="bbbbbbbb";	
	char* str3;
	char* str4;
	str3=(char *)srcfile_info;

	cout << "my_strdup(str1): " << my_strdup(str1) << endl;
	cout << "my_strdup(str2): " << my_strdup(str2) << endl;
	cout << "my_strdup(str3): " << my_strdup(str3) << endl;

	str4 = my_strstr(str3, "b");
	cout << "my_strstr(str3, \"b\")" << ((str4)?str4:"") << endl;
	cout << endl;
	
	make_str();
	return 0;
}

// join s1 and s2 separated by "."
// return c-style-string
char* cat_dot(const char* s1, const char* s2)
{
	// size of two strings + "." and "\0"
	int size = strlen(s1)+strlen(s2)+2;
	char* str = new char[size]; // allocate space for new string
	// copy s1 to str

	// concatenate "." separator

	// concatenate s2 to str

	// append "\0" to end of str
}

char* my_strdup(const char* str)
{
	int len = 0;

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

// return the first occurrance of x in s
char* my_strstr(const char* s, const char* x)
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
	cout << " at " << __TIME__ << "\n\n";
	return;
}
