/**
 * @author Jason Angus
 * @file ch17ex07.cpp
 * @date 2011-08-28
 *
 * 7. Write a program that reads characters from cin into an array that you
 *    allocate on the free store. Read individual characters until an
 *    exclamation mark (!) is entered. Do not use a std::string.
 *    Do not worry about memory exhaustion.
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
	const int block = 8; // memory allocation chunk size
	char* ch_array = new char[block]; // store user input
	int i=0; // index into array

	cout << "please enter some characters, '!' to end: ";

	while (true) {
		cin >> ch_array[i];
		if (ch_array[i++] == '!')
			break;
	}
	ch_array[i]='\0';
	cout << "ch_array: " << ch_array << endl;

	return 0;
}

void srcfile_info()
{
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__;
  cout << " at " << __TIME__ << "\n\n";
  return;
}
