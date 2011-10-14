/**
 * @author Jason Angus
 * @file ch17ex09.cpp
 * @date 2011-08-28
 *
 * 9. Which way does the stack grow: up (toward higher addresses) or down
 *    (toward lower addresses)? Which way does the free store initially grow
 *    (that is, before you use delete)? Write a program to determine the answers.
 */

//#include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

void srcfile_info(); // display basic source file information

void fa(int fai)
{
	static int call = 0;
	++call;
	cout << "fa(), call: " << call << ", &fai: " << &fai<< endl;

	if (call == 10)
		return;
	else
		fa(2);
}

int main()
{
	srcfile_info();
	const int block = 1; // memory allocation chunk size
	char* ch_array=0;

	fa(3);

	for (int i=0; i<10; ++i) {
		ch_array=new char[block];
		cout << "&ch_array: " << (void *)ch_array << endl;
	}

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}
