/**
 * @author Jason Angus
 * @file txt2bin.cpp
 * @date 2011-07-23
 *
 * solution to exercise 11.08 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 *
 * 8. Write a program that reads a text file and writes it out as a binary file.
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

void error(const string& s1, const string& s2); // print error and exit
template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}


/**
 * reads a text file and saves it as a binary file
 */
int main(int argc, char** argv)
{
	cout << "txt2bin.cpp, solution to exercise 11.08 in PPP\n";
	vector<string> args; // lets try to store command line args here...
	vector<string> line_buf; // temporary string storage
	vector<int> binary_buf; // hold binary converted lines
	string str_in; // data read into str_in
	ifstream fin; // our input file stream fror reading data
	ofstream fout; // our output file stream for writing data
	fstream iofs; // a file opened for reading and writng
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

	fin.open(ifname.c_str(), std::ios_base::binary);
	if (!fin) error("cannot open input file", ifname);
	fout.open(ofname.c_str(), std::ios_base::binary);
	if (!fout) error("cannot open output file", ofname);

	int data;
	while (fin.read(as_bytes(data), sizeof(int))) {
		fout.write(as_bytes(data), sizeof(int));
	}

	return 0;
} // end main()


// print error and exit
void error(const string& s1, const string& s2 = "")
{
	std::cerr << s1 << ' ' << s2 << endl;
	exit(EXIT_FAILURE);
}