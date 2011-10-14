/**
 * @author Jason Angus
 * @file ch17ex08.cpp
 * @date 2011-08-28
 *
 * 8. Do exercise 7 again, but this time read into a std::string rather than to
 *    memory you put on the free store (string knows how to use the free store
 *    for you).
 */

//#include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

void srcfile_info(); // display basic source file information

int main()
{
	srcfile_info();
	//const int block = 8; // memory allocation chunk size
	char ch='\0'; // store user input
	string str; // store characters entered
	size_t strcap = 0; // store capaciity of str

	cout << "Max size of str: " << str.max_size() << endl;

	// this will cause an exception when we try to push_back() the next char
	//str.resize(str.max_size());

	cout << "str.capacity: " << str.capacity() << endl;

	cout << "please enter some characters, '!' to end: ";

	while (ch!='!') {
		cin >> ch;
		str.push_back(ch);
		if (str.capacity() > strcap) {
			cout << "str.capacity: " << str.capacity() << endl;
			strcap = str.capacity();
		}
	}
	cout << "str: " << str << endl;

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}
