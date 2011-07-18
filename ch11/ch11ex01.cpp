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
	string fin_name = "input"; // default name for input file
	size_t read_buf = 80; // amount of char to read at one time
	ofstream fout; // our output file stream for writing data
	string fout_name = "output"; // default name for output file

	// open input file
	if (argc>1) // use first command-line arg as input filename
		fin_name=argv[1];
	fin.open(fin_name.c_str());
	if (!fin) {
		cout << "ERROR: Unable to open file, \"" << fin_name << "\"\n";
		cout << "Trying default \"input\"...\n";
		fin_name="input";
		fin.clear();
		fin.open(fin_name.c_str());
		if (!fin) {
			cout << "ERROR: Unable to open file, \"" << fin_name << "\"\n";
			exit(EXIT_FAILURE);
		}
	} // open input file

	// main processing loop, read lines from file, convert to lower case
	// store converted lines in a vector, ready to write out to output file
	while (fin.good() && !fin.eof()) {
		getline(fin,str_in); //, read_buf, fin);
		for (size_t i=0; i<str_in.size(); ++i)
			str_in[i]=tolower(str_in[i]);
		lower_line.push_back(str_in);
	}

	// open output file and write tolower out

	for (size_t i=0; i<lower_line.size(); ++i)
		cout << "lower_line[" << i << "]: " << lower_line[i] << endl;

	for (int i=0; i<argc; ++i) {
		args.push_back(argv[i]);
	}

	for (unsigned i=0; i<args.size(); ++i) {
		cout << "args[" << i << "]: " << args[i] << endl;
		for (unsigned j=0; j<args[i].size(); ++j) {
			cout << "args["<<i<<"]["<<j<<"]: " << args[i][j] << endl;
			str_in.push_back(tolower(args[i][j]));
		}
		//cout << "temp.size(): " << temp.size() << endl;
		cout << "temp: " << str_in << endl;
		str_in = "";
	}
	//vector<string>::const_iterator it = args.begin();
	/*
	while (it!=args.end()) {
		cout << *it << endl;
		//temp = *it;
		//cout << "temp: " << temp << endl;
		for (size_t i=0; i<it->size(); ++i)
			temp.push_back(tolower(it->[i]));
			//cout << (char)tolower(temp[i]);
		cout << temp << endl;
		++it;
	}
*/

	return 0;
}
