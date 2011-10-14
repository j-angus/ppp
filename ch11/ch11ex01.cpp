/**
 * @author Jason Angus
 * @file ch11ex01.cpp
 * @date 2011-07-16
 *
 * solution to exercise 11.01 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 * 1. Write a program that reads a text file and converts its input to all lower
 * case, producing a new file.
 */

#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <cctype> // for tolower()
#include <cstdlib> // for exit(), EXIT STATUS...
int main(int argc, char** argv)
{
	cout << "ch11ex01.cpp, solution to exercise 11.01 in PPP\n";
	vector<string> args; // lets try to store command line args here...
	vector<string> lower_line; // hold lower case coonverted lines
	string str_in; // data read into str_in
	ifstream fin; // our input file stream fror reading data
	const string def_ifname = "input"; // default name for input file
	string ifname = def_ifname; // set input filename to default
	ofstream fout; // our output file stream for writing data
	const string def_ofname = "output"; // default name for output file
	string ofname = def_ofname; // set output filename to default

	// open input file
	if (argc>1) // use first command-line arg as input filename
		ifname=argv[1];
	fin.open(ifname.c_str());
	if (!fin) {
		cout << "ERROR: Unable to open file, \"" << ifname << "\"\n";
		if (ifname != def_ifname) {
			ifname=def_ifname;
			cout << "Trying default input file: \"" << ifname << "\"...\n";
			fin.clear();
			fin.open(ifname.c_str());
			if (!fin) {
				cout << "ERROR: Unable to open file, \"" << ifname << "\"\n";
				exit(EXIT_FAILURE);
			}
		}
	} // open input file

	// main processing loop, read lines from file, convert to lower case
	// store converted lines in a vector, ready to write out to output file
	int line_in = 1; // count lines being read
	while (fin.good() && !fin.eof()) {
		getline(fin,str_in); //, read_buf, fin);
		for (size_t i=0; i<str_in.size(); ++i)
			str_in[i]=tolower(str_in[i]);
		lower_line.push_back(str_in);
		cout << "Reading line no. " << line_in++ << endl;
	}

	// open output file and write tolower out
	cout << "argc: " << argc << endl;
	if (argc>2) { // use second command-line arg as output filename
		cout << "argv[2]: " << argv[2] << endl;
		ofname=argv[2];
	}
	fout.open(ofname.c_str());
	if (!fout) {
		cout << "ERROR: Unable to open file, \"" << ofname << "\"\n";
		if (ofname != def_ofname) {
			ofname=def_ofname;
			cout << "Trying default output file: \"" << ofname << "\"...\n";
			fout.clear();
			fout.open(ofname.c_str());
			if (!fout) {
				cout << "ERROR: Unable to open file, \"" << ofname << "\"\n";
				exit(EXIT_FAILURE);
			}
		}
	} // open output file

	// loop to write converted lines to output file
	int line_out = 1; // count lines being written
	for (size_t i=0; i<lower_line.size(); ++i) {
		fout << lower_line[i] << endl;
		cout << "Writing line no. " << line_out++ << endl;
		// check that file is still in good shape for writing
		if (!fout.good()) {
			cout << "ERROR: Write error to file, \"" << ofname << "\"\n";
			cout << "fout status: " << fout.rdstate() << endl;
		}
	}
	// explicitly close output file
	fout.close();

	return 0;
}
