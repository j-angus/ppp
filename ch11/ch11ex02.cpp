/**
 * @author Jason Angus
 * @file ch11ex02.cpp
 * @date 2011-07-20
 *
 * solution to exercise 11.02 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 * 2. Write a program that removes all vowels from a file ("disemwowels").
 * For example, Once upon a time! becomes nc pn tm!. Surprisingly often, the
 * result is still readable; try it on your friends.
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


	if (argc>2) {
		// get command-line args
		 for (int i=1; i<argc; ++i)
			args.push_back(argv[i]);
		ifname = args[0];
		ofname = args[1];
	}
	else {
		cout << "ERROR: no filenames given.\n";
		exit(EXIT_FAILURE);
	}

	// open input file
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
		if (!fin.eof() || (str_in.size()>0)) { // we will read the last line
											   // of a file that is not
											   // newline terminated, as well as
											   // not reading an extra empty
											   // line at the end of a file
			line_buf.push_back(str_in); // loads vector with line from file
			cout << "Reading line no. " << line_in++ << endl;
			cout << "str_in size: " << str_in.size() << endl;
		}
	}
	fin.close();

	// process line_buf
	for (size_t i=0; i<line_buf.size(); ++ i) {
		line_buf[i] = remove_vowels(line_buf[i]);
	}

	// open output file
	// ofname = args[0];
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
		cout << "line_buf[" << i << "] size: " << line_buf[i].size() << endl;
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
	string::iterator it = line.begin(); // we need an iterator for erase
	char test_char;
	for (size_t i=0;i < line.size(); ) {
		test_char = tolower(line[i]);
		switch (test_char) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			it = line.begin()+i;
			line.erase(it);
			// we don't increment the index when we erase a vowel, the next
			// char moves into the currently indexed postion
			break;
		default:
			++i; // not a vowel, let's look at the next char
		}
	}
	return line;
}
