/**
 * @file ch10ex11.cpp
 * @date 2011-07-08
 *
 * 11. Write a program that produces the sum of all the whitespace-separated
 * integers in a text file. For example, "bears: 17 elephants 9 end " should
 * output 26.
 */

#include "../std_lib_facilities.h"

void show_state(istringstream &iss); // show state of stream

int main()
{
	const string ifname="intext"; // input filename
	vector<string> word; // store words from in files
	vector<int> numbers; // from input file
	int num; // temp store before adding to numbers vector
	int total =0;
	string str; // temporary store prior to placing into word
	size_t first_not_converted; // use with stoi() to test for int conversion... maybe...

	try {
		// open file for reading
		ifstream ist(ifname.c_str());
		if (!ist) error("can't open input file: ", ifname);
		// make ist throw if it goes bad
		ist.exceptions(ist.exceptions()|ios_base::badbit);
		istringstream is; // use to convert string to ints...
		// is.clear();

		while (ist >> str) {
			cout << "str: " << str << endl;
			is.str(str); // place string into istringstream
			cout << "is.str(): ." << is.str() << ".\n";

			is >> num; // attempt to convert string to int
			if (is.rdstate() & istringstream::failbit) // check to see whether conversion to in succeeded
				cout <<"Error: Conversion to int failed\n";
			show_state(is);
			is.clear(); // reset errors/state of is...required after using is, clears failed bits
			show_state(is);
			if (num) {
				cout << "num: " << num << endl;
				total+=num;
				cout << "total: " << total << endl;
			}
		}
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}

void show_state(istringstream &iss)
{
	if (iss.rdstate() & istringstream::failbit)
		cout << "failbit up: " << istringstream::failbit << endl;
	if (iss.rdstate() & istringstream::eofbit)
		cout << "eofbit up: " << istringstream::eofbit << endl;
	if (iss.rdstate() & istringstream::badbit)
		cout << "badbit up: " << istringstream::badbit << endl;
	if (iss.rdstate() & istringstream::failbit)
		cout << "goodbit up: " << istringstream::goodbit << endl;
	return;
}


