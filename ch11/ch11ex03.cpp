/**
 * @author Jason Angus
 * @file ch11ex03.cpp
 * @date 2011-07-22
 *
 * solution to exercise 11.03 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 *
 * 3. Write a program that prompts the user to enter several integers in any
 * combination of octal, decimal , or hexadecimal, using thc 0 and 0x base
 * suffixes; interprets the numbers correctly; and converts them to decimal
 * form. Then your program should output the values in properly spaced columns
 * like this:
 * 0x4		hexadecimal	converts to		67		decimal
 * 0123		octal		converts to		83		decimal
 * 65		decimal		converts to 	65		decimal
 */


#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <cctype> // for tolower()
#include <cstdlib> // for exit(), EXIT STATUS...

// attempts to open an fstream
// returned fstream state good if the file is opened successfully
bool open_ifile(ifstream& ifs, const string& fname);
bool open_ofile(ofstream& ofs, const string& fname);
fstream& open_iofile(fstream& iofs, const string& fname);
string& remove_vowels(string& line); // remove vowels from line

/**
 * removes vowels from a text file.
 * expects filename to be passed as a command line argument.
 * modifies the file if it contains vowels and saves it.
 */
int main(int argc, char** argv)
{
	cout << "ch11ex02.cpp, solution to exercise 11.02 in PPP\n";
	vector<string> args; // lets try to store command line args here...
	vector<string> line_buf; // temporary string storage
	vector<string> lower_line; // hold lower case coonverted lines
	string str_in; // data read into str_in
	ifstream fin; // our input file stream fror reading data
	ofstream fout; // our output file stream for writing data
	fstream iofs; // a file opened for reading and writng
	string iofname; // input / output filename
	string ifname; // input filename
	string ofname; // output filename


	if (argc>1) {
		// get command-line args
		 for (int i=1; i<argc; ++i)
			args.push_back(argv[i]);
	}
	else {
		cout << "ERROR: no filename given.\n";
		exit(EXIT_FAILURE);
	}
	// open input file
	ifname = args[0];
	open_ifile(fin, ifname.c_str());
	if (!fin) {
		cout << "ERROR: Unable to open file, \"" << ifname << "\"\n";
		cout << "fout status: " << fin.rdstate() << endl;
		exit(EXIT_FAILURE);
	}

	// file reading loop.
	// store  lines in a vector, ready to process
	int line_in = 1; // count lines being read

	while (fin.good() && !fin.eof()) {
		getline(fin,str_in);
		line_buf.push_back(str_in); // load our vector with lines from file
	}
	fin.close();

	// process line_buf
	for (size_t i=0; i<line_buf.size(); ++ i) {
		line_buf[i] = remove_vowels(line_buf[i]);
	}

	// open output file
	ofname = args[0];
	open_ofile(fout, ofname.c_str());
	if (!fout) {
		cout << "ERROR: Unable to open file, \"" << ofname << "\"\n";
		cout << "fout status: " << fout.rdstate() << endl;
		exit(EXIT_FAILURE);
	}

	// loop writes lower case converted lines to output file
	int line_out = 1; // count lines being written
	for (size_t i=0; i<line_buf.size(); ++i) {
		fout << line_buf[i] << endl;
		cout << "Writing line no. " << line_out++ << endl;
		// check that file is still in good shape for writing
		if (!fout.good()) {
			cout << "ERROR: Write to file failed, \"" << ofname << "\"\n";
			cout << "fout status: " << fout.rdstate() << endl;
		}
	}
	fout.close();

	return 0;
} // end main()

// attempts to open an fstream
// returns true if the file is opened successfully
bool open_ifile(ifstream& ifs, const string& fname)
{
	cout << "DEBUG: open_ifile()\n";
	ifs.close(); // close fstream in case it was already open
	ifs.clear(); // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	ifs.open(fname.c_str()); // open the file we were given
	return (ifs.good() ? true : false); // true if condition state is good
}

bool open_ofile(ofstream& ofs, const string& fname)
{
	cout << "DEBUG: open_ofile()\n";
	ofs.close(); // close stream in case it was already open
	ofs.clear(); // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	ofs.open(fname.c_str()); // open the file we were given
	return (ofs.good() ? true : false); // true if condition state is good
}

fstream& open_iofile(fstream& iofs, const string& fname)
{
	cout << "DEBUG: open_iofile()\n";
	iofs.close(); // close fstream in case it was already open
	iofs.clear(); // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	iofs.open(fname.c_str()); // open the file we were given
	return iofs; // condition state is good if open succeeded
}

// remove vowels from line
string& remove_vowels(string& line)
{
	string::iterator it = line.begin();

	for (size_t i=0;i < line.size(); ++i) {
		switch ((char)tolower(line[i])) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			it = line.begin()+i;
			line.erase(it);
			break;
		}
	}
	return line;
}
