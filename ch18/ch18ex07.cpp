/**
 * @author Jason Angus
 * @file ch18ex07.cpp
 * @date 2011-09-16
 * Last edit: 2011-09-16
 * 
 * 7. Write versions of the cat_dot()s from the previous exercises to take 
 *    C-style strings as arguments and return a free-store-allocated C-style 
 *    string as the result. Do not use standard library functions or types in 
 *    the implementation. Test these functions with several strings. Be sure to
 *    free (using delele) all the memory you allocated from free Store (using 
 *    new). Compare the effort involved in this exercise with the effort 
 *    involved for exercises 5 and 6.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//#include <string>
//using std::string;


void srcfile_info(); // display basic source file information

char* my_strdup(const char* str);
char* my_strstr(const char* s, const char* x);
int my_strcmp(const char* s1, const char* s2);
char* cat_dot(const char* s1, const char* s2);
char* cat_sep(const char* s1, const char* s2, const char* sep);

int main()
{
	srcfile_info();
	// test some c-string functions
	char str1[]="string1";
	char str2[]="string2";
	char sep[]="_._";
	char* str3 = cat_dot(str1,str2);

	cout << "cat_dot(str1,str2): " << str3 << endl;
	// str1[0]='\0'; // truncate str1
	// str3 = cat_dot(str1,str2);
	// cout << "cat_dot(str1,str2): " << str3 << endl;
	// str2[0]='\0'; // truncate str2
	// str3 = cat_dot(str1,str2);
	// cout << "cat_dot(str1,str2): " << str3 << endl;

	cout << "Test cat_sep():\n";
	str3 = cat_sep(str1,str2,sep);
	cout << "cat_sep(str1,str2,sep): " << str3 << endl;

	delete[] str3;

	return 0;
}

// join s1 and s2 separated by "."
// return c-style-string
char* cat_dot(const char* s1, const char* s2)
{
	// size of two strings + "." and "\0"
	//int size = strlen(s1)+strlen(s2)+2;
	int size=2; // total size required for concatenated string
	int sz=0; // used to store calculated size of individual strings

	// cout << "s1@ " << (void* )s1 << endl; // addr of s1
	while (*s1) {
		++s1;
		++sz;
	}
	size+=sz;
	s1-=sz;
	sz=0;
	// cout << "s1@ " << (void* )s1 << endl; // display addr of s1
	// cout << "s2@ " << s2 << endl;

	while (*s2) {
		++s2;
		++sz;
	}
	s2-=sz;
	size+=sz;
	// cout << "s2@ " << s2 << endl;
	cout << "cat_dot(), total size=" << size << endl;

	char* str = new char[size]; // allocate space for new string

	// copy s1 to str
	while (*s1)
		*str++=*s1++;

	// concatenate "." separator
	*str++='.';
	// concatenate s2 to str
	while (*s2)
		*str++=*s2++;

	// append "\0" to end of str
	*str++='\0'; // null terminate string
	return str-size;
}

// join s1 and s2 separated by "sep"
// return c-style-string
char* cat_sep(const char* s1, const char* s2, const char* sep)
{
	// size of two strings + sep and "\0"
	//int size = strlen(s1)+strlen(s2)+strlen(sep)+1;
	int size=1; // total size required for concatenated string
	int sz=0; // used to store calculated size of individual strings

	// calculate size of strings s1 and s2 and sep
	// size of sep
	while (*sep) {
		++sep;
		++sz;
	}
	size+=sz;
	sep-=sz;
	sz=0;
	// size of s1
	while (*s1) {
		++s1;
		++sz;
	}
	size+=sz;
	s1-=sz;
	sz=0;
	// size of s2
	while (*s2) {
		++s2;
		++sz;
	}
	size+=sz;
	s2-=sz;
	sz=0;
	cout << "cat_sep(), total size=" << size << endl;
	
	// allocate space for new string
	char* str = new char[size]; 
	// copy s1 to str
	while (*s1)
		*str++=*s1++;

	// concatenate  separator
	while (*sep)
		*str++=*sep++;

	// concatenate s2 to str
	while (*s2)
		*str++=*s2++;

	// append "\0" to end of str
	*str++='\0'; // null terminate string
	return str-size;
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
