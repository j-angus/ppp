/**
 * @file ch10ex08.cpp
 * @date 2011-07-05
 *
 * 8. Write a program that accepts two file names and produccs a new file that
 * is the contents of the first file followed by the contents of the second;
 * that is, the program concatenates the two files.
 */

#include "../std_lib_facilities.h"

int main()
{
	const string ifname="in_text"; // input filename
	const string ofname="out_text"; // output filename
	vector<string> line; // store lines of text from ifname
	string str; // temporary store prior to placing into line
	string out_lines = "a line\n yet another line.\nhmmm, last line baby!\n";

	try {
		// open file for reading
		ifstream ist(ifname.c_str());
		if (!ist) error("can't open input file: ", ifname);
		// make ist throw if it goes bad
		ist.exceptions(ist.exceptions()|ios_base::badbit);

		while (getline(ist, str))
			line.push_back(str + "\n");
		if (ist.eof()) cout << "OK: reached eof.\n";

		// open file for reading
		ofstream ost(ofname.c_str());
		if (!ost) error("can't open output file: ", ofname);
		// make ost throw if it goes bad
		ost.exceptions(ost.exceptions()|ios_base::badbit);

		line.push_back(out_lines);
		for (uint i=0; i<line.size(); ++i)
			ost << line[i];
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}

