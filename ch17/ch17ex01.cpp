/**
 * @file ch17ex01.cpp
 * @date 2011-08-26
 *
 * 1. What is the output format of pointer values on your implementation?
 *    Hint : Don't read the documentation.
 */

// #include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void srcfile_info(); // display basic source file information

int main()
{
	srcfile_info();
	const int size = 6;
	int ia[size];

	for (int i=0; i<size; ++i)
		cout << "Address ia[" << i << "]: " << &ia[i] << endl;

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}