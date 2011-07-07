/**
 * @file ch10ex08.cpp
 * @date 2011-07-05
 *
 * 9. Write a program that takes two files containing sorted whitespace-separated
 * words and merges them, preserving order.
 */

#include "../std_lib_facilities.h"

int main()
{
	const string if_a="in_a"; // input filename
	const string if_b="in_b"; // input filename
	const string of_merged="merged_ab"; // output filename
	vector<string> word; // store words from in files
	string str; // temporary store prior to placing into word
	bool isunique = true; // flag set false if word is already present

	try {
		// open file for reading
		ifstream ist(if_a.c_str());
		if (!ist) error("can't open input file: ", if_a);
		// make ist throw if it goes bad
		ist.exceptions(ist.exceptions()|ios_base::badbit);

		while (ist >> str) {
			for (uint i=0; i<word.size(); ++i) {
				if (word[i]==str) {
					isunique=false;
					break;
				}
			}
			if (isunique)
				word.push_back(str);
			isunique=true; // reset flag
		}
		if (ist.eof()) cout << "OK: reached eof in: " << if_a <<endl;
		ist.close();

		// open file for reading
		ist.open(if_b.c_str());
		if (!ist) error("can't open input file: ", if_b);
		// make ist throw if it goes bad
		ist.exceptions(ist.exceptions()|ios_base::badbit);

		while (ist >> str) {
			for (uint i=0; i<word.size(); ++i) {
				if (word[i]==str) {
					isunique=false;
					break;
				}
			}
			if (isunique)
				word.push_back(str);
			isunique=true; // reset flag
		}
		if (ist.eof()) cout << "OK: reached eof in: " << if_b << endl;

		sort(word.begin(), word.end());

		// open file for writing
		ofstream ost(of_merged.c_str());
		if (!ost) error("can't open output file: ", of_merged);
		// make ost throw if it goes bad
		ost.exceptions(ost.exceptions()|ios_base::badbit);

		for (uint i=0; i<word.size(); ++i)
			ost << word[i] << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}

