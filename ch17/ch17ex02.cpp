/**
 * @author Jason Angus
 * @file ch17ex02.cpp
 * @date 2011-08-26
 *
 * 2. How many bytes are there in an int? In a double? In a bool?
 * Do not use sizeof except to verify your answer.
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
	const int size = 3;
	int ia[size];
	double da[size];
	bool ba[size];

	for (int i=0; i<size; ++i) {
		cout << "Address ia[" << i << "]: " << &ia[i] << endl;
		cout << "Address da[" << i << "]: " << &da[i] << endl;
		cout << "Address ba[" << i << "]: " << &ba[i] << endl;
	}
	int isz = ((char *)&(ia[1]) - (char *)&(ia[0]));
	int dsz = ((char *)&(da[1]) - (char *)&(da[0]));
	int bsz = ((char *)&(ba[1]) - (char *)&(ba[0]));

	cout << "Bytes in an int: " << isz << endl;
	cout << "Bytes in a double: " << dsz << endl;
	cout << "Bytes in a bool: " << bsz << endl;
	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}