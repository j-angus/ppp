/**
 * @file ch10ex12.cpp
 * @date 2011-07-11
 *
 * 12. Write a program that given a file name and a word outputs each line that
 * contains that word together with the line number. Hint: getline().
 */

#include "../std_lib_facilities.h"

void show_state(istringstream &iss); // show state of stream
void usage(void); // print basic program usage
int main(int argc, char** argv)
{
	if (argc < 3) {
		usage();
		exit(EXIT_FAILURE);
	}
	const string ifname=argv[1]; // input filename
	const string target = argv[2]; // word to search for in ifname
	string line; // store a line read from input file
	string cur_word; // current word read from LINE to compare with TARGET
	int linenum = 0; // current line number within input file

	string str; // temporary store prior to placing into word

	try {
		// open file for reading
		ifstream input_file(ifname.c_str());
		if (!input_file) error("can't open input file: ", ifname);
		// make input_file throw if it goes bad
		input_file.exceptions(input_file.exceptions()|ios_base::badbit);
		istringstream iss; // use to parse string into separate words

		while (getline(input_file, line)) {
			++linenum;
			show_state(iss);
			iss.str(line); // place string into istringstream
			while (iss >> cur_word) {
				if (cur_word == target) {
					cout << "line " << linenum << ": " << line << endl;
					break;
				}
			}
			// if we don't find any matching words in iss,
			// its eofbit and failbits will be set, so we have to clear iss
			// before trying place any further strings into it.
			iss.clear();
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
	if (!(iss.rdstate() & istringstream::goodbit))
		cout << "goodbit up (no flags set): " << istringstream::goodbit << endl;
	/*
	cout << "iss.rdstate(): " << iss.rdstate() << endl;
	cout << "istringstream::goodbit: " << istringstream::goodbit << endl;
	cout << "!(iss.rdstate() & istringstream::goodbit): " <<
			!(iss.rdstate() & istringstream::goodbit) << endl;
	*/
	return;
}

/**
 * print basic program usage
 */
void usage(void)
{
	cout << "Usage: fw FILENAME WORD\n";
	cout << "Prints out occurrences of WORD in FILENAME.\n";
	return;
}
