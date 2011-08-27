/**
 * @author Jason Angus
 * @file ch17ex05.cpp
 * @date 2011-08-27
 *
 * 5. Write a function , char* findx (const char* s, const char* x), that
 *    finds the first occurrence of the C-style string x in s.
 */

// #include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void srcfile_info(); // display basic source file information

// copy a c-style string to a new memory location
const char* findx (const char* s, const char* x);

// returns the number of charcters in a c-style string excluding null termination
int str_len(const char* s);

int main()
{
	srcfile_info();

	char str[] = "abcdefgh";
	char str2[] = "dex";
	const char* pin = findx(str, str2);

	cout << "str: " << str << endl;
	cout << "str_len(str): " << str_len(str) << endl;
	cout << "findx(str, str2):" << pin << endl;

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}

int str_len(const char* s)
{
	const int MAXLEN = 512; // max allowable string length
	int len=0; // calculated length of string, 0 == error (null str, not null terminated, too long)
	if (*s){
		for (int i=0; i<MAXLEN; ++i)
			if (s[i])
				++len;
			else
				break; // end of string s
	}

	if (len==MAXLEN)
		if(s[MAXLEN])
			len = 0; // string too long and not null terminated

	return len;
}

const char* findx (const char* s, const char* x)
{
	const char* loc=0; // location of x within s
	bool found = false;

	int s_len = 0;
	int x_len = 0;
	int i=0;

	if (*s && *x) {
		s_len = str_len(s);
		x_len = str_len(x);
		if (s_len >= x_len) {
			for (; i<s_len; ++i) {
				cout << "outer i: "<< i << endl;
				for (int j=0; j<x_len; ++j) {
					cout << "inner j: " << j << endl;
					if (x[j] == s[i+j]) {
						cout << "found char\n";
						if (j==x_len-1)
							found = true;
					}
					else {
						cout << "xj != si\n";
						break;
					}
				}
				if (found == true) {
					cout << "found sub string\n";
					break;
				}
			}
		}
	}

	if (found)
		return &s[i];
	else
		cout << "sub string not found.\n";
	return loc;
}