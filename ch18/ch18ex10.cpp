/**
 * @author Jason Angus
 * @file ch18ex10.cpp
 * @date 2011-10-03
 *
 * 10. Look at the "array solution" to the palindrome problem in §18.6.2. Fix it
 *     to deal with long strings by (a) reporting if an input string was too 
 *     long and (b) allowing an arbitrarily long string. Comment on the 
 *     complexity of the two versions.
 */


#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;

#include <cstring>

// s points to the first character of an array of n characters
bool is_palindrome(const char s[], int n);


void srcfile_info(); // display basic source file information

// read at most max - 1 characters from is into buffer
istream& read_word(istream& is, char* buffer, int max);

int main()
{
	srcfile_info();
	cout << "main()\n";
	const int max=6;
	char buf[max]; // array to hold user input

	for (int i=0; i<max; ++i)
		buf[i]='x';

	while (read_word(cin,buf,max)) {
		cout << "buf is: " << buf << endl;
		cout << "length of buf is: " << strlen(buf) << endl;

		for (int i=0; i<max; ++i) {
			cout << "buf[" << i << "]: ";
	       		if (buf[i])
			       cout << buf[i] << endl;
			else
			       cout <<	"\"nul\"" << endl;
		}
	}

	return 0;
}


// s points to the first character of an array of n characters
bool is_palindrome(const char s[], int n)
{
	cout << "is_palindrome()\n";
	int first=0; // index of first letter
	int last=n-1; // index of last letter

	while (first < last) { // we haven't reached the middle
		if (s[first]!=s[last]) return false;
		++first; // move forward
		--last; // move backward
	}
	return true;
}

istream& read_word(istream& is, char* buffer, int max)
// read at most max - 1 characters from is into buffer
// use ctl-d (EOF) to end this function
{
	cout << "read_word()\n";
//	is.width(max);  // read at most max - 1 characters in the next >>
//	is >> buffer;   // read whitespace-terminated word,
			// add zero after the last character read into p
	// Problem with above functions:
	// unable to determine whether there was more text to be read
	// is >> buffer automatically nul terminates strings that are too
	// long to fit into the buffer
	is.getline(buffer, max);
	//is.get(buffer, max);
	cout << "is.good(): " << is.good() << endl;
	cout << "is.eof(): " << is.eof() << endl;
	cout << "is.fail(): " << is.fail() << endl;
	cout << "num char read: " << is.gcount() << endl;

	// check for number of char exceeding max
	// gcount == max-1 and fail bit set if too many char 
	if (is.gcount()==max-1 && is.fail()) { // too many char
		cout << "ERROR: too many characters to fit in buffer.\n";
		is.clear();
		cout << "is cleared\n";
	}

	return is;
}


void srcfile_info()
{
	cout << "srcfile_info()\n";
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}
