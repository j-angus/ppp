/**
 * @author Jason Angus
 * @file ch17ex07.cpp
 * @date 2011-08-28
 *
 * 6. This chapter docs not say what happens when you run out of memory
 *    using new. That's called memory exhaustion. Find out what happens.
 *    You have two obvious alternatives: look for documentation, or write a
 *    program with an infinite loop that allocates but never deallocatcs.
 *    Try both. Approximately how much memory did you manage to allocate before
 *    failing?
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
	const int block = 4096; // memory allocation chunk size
	double mem_alloc=0; // counter
	char* stealer = 0;

	while (true) {
		stealer = new char[block];
		mem_alloc += block;
		cout << "mem_alloc: " << mem_alloc/(1024*1024*1024) << "GiB\n";
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
