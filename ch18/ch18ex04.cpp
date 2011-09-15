/**
 * @author Jason Angus
 * @file ch18ex04.cpp
 * @date 2011-09-14
 *
 * 4. Consider what happens if you give strdup(), findx(), and slrcmp() an 
 *    argument that is not a C-style string. Try it! First figure out how to 
 *    get a char * that doesn't point to a zero-terminated array of characters 
 *    and then use it (never do this in real - non-experimental - code; it can 
 *    create havoc). Try with free -store-allocated and stack-allocated "fake 
 *    C -style strings." If the results still look reasonable, turn off debug 
 *    mode. Re-design and re-implement those three functions so that they take 
 *    another argument giving the maximum number of elements allowed in argument
 *    strings. Then, test that with correct C-style strings and "bad" strings.
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
void make_str()
{
	cout << "make_str()\n";
	char* str1;
	str1=(char*)srcfile_info;
	char* str4;


	cout << "my_strdup(str1): " << my_strdup(str1) << endl;
	str4=my_strstr(str1, "b");	
	cout << "my_strstr(str1, \"b\")" << ((str4)?str4:"") << endl;
	return;
}

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
