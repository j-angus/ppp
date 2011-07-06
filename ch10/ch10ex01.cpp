/**
 * @file ch10ex01.cpp
 * @date 2011-07-05
 *
 * 1. Write a program that produces the sum of all the numbers in a file of
 *	white space-separated integers.
 */

#include "../std_lib_facilities.h"

int main()
{
	const string fname="ints.txt"; // filename

	try {
		int int_from_file; // read from file
		int ifftotal=0; // total of ints  from file

		// read data from file
		ifstream ist(fname.c_str());
		if (!ist) error("can't open input file: ", fname);
		// make ist throw if it goes bad
		ist.exceptions(ist.exceptions()|ios_base::badbit);

		while (ist >> int_from_file)
			ifftotal+=int_from_file;
		if (ist.eof()) cout << "OK: reached eof.\n";
		cout << "ifftotal: \n" << ifftotal << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}


