/**
 * @author Jason Angus
 * @file ch18ex10b.cpp
 * @date 2011-10-05
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
#include <limits>
using std::numeric_limits;

// s points to the first character of an array of n characters
bool is_palindrome(const char s[], int n);

void srcfile_info(); // display basic source file information

// read at most max - 1 characters from is into buffer
istream& read_word(istream& is, char*& buffer);

int main()
{
	srcfile_info();
	cout << "main()\n";
	// const int max=6;
	//char buf[max]; // array to hold user input
	char* buf; // array to hold user input

	//cout << "buf: " << (int)buf << endl;
	//cout << "Max value for int: " << numeric_limits<int>::max() << endl;

	while (read_word(cin,buf)) {
		cout << buf << endl;
		cout << "is_palindrome():\n";
		cout << is_palindrome(buf,strlen(buf)) << endl;

/*
		cout << "buf: " << (int)buf << endl;
		cout << "buf is: " << buf << endl;
		cout << "length of buf is: " << strlen(buf) << endl;

		for (int i=0; i<strlen(buf); ++i) {
			cout << "buf[" << i << "]: ";
	       		if (buf[i])
			       cout << buf[i] << endl;
			else
			       cout <<	"\"nul\"" << endl;
		}
*/
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

istream& read_word(istream& is, char*& buffer)
// read an arbitrary amount of characters from is into buffer
// use ctl-d (EOF) to end this function
{
	cout << "read_word()\n";
	char* str; // store user entered char - dynamically expand as required
	int bufsz=2; // initial size of str buffer
	int nchar=0; // number of char already stored in str
	str=new char[bufsz]; // init str buffer
	bool more_char=true; // are there more char to read?

	while (more_char) {
	more_char=false; //clear flag	
	is.getline(str+nchar, bufsz-nchar); // read at most max - 1 characters 
                                 // read whitespace-terminated word,
			         // add zero after the last character read 
/*
	cout << "is.good(): " << is.good() << endl;
	cout << "is.eof(): " << is.eof() << endl;
	cout << "is.fail(): " << is.fail() << endl;
	cout << "num char read: " << is.gcount() << endl;
*/
	// check for number of char exceeding max
	// gcount == bufsz-1 and fail bit set if too many char 
	if (is.gcount()==bufsz-1-nchar && is.fail()) { // too many char
		cout << "ERROR: too many characters to fit in buffer.\n";
		is.clear();
		cout << "is cleared\n";

		// limit max size of memory to hold char in str
		if (bufsz*2 < numeric_limits<int>::max()) {
	//	if (bufsz*2 < 12) {
			more_char=true; // more char waiting to be read
			bufsz*=2;	
			char* tmp=new char[bufsz]; // increase str buffer size
			// copy str to tmp
			nchar=strlen(str);
			for (int i=0;i<nchar;++i)
				tmp[i]=str[i];
			delete[] str;
			str=tmp;
		}
		else { // not enough memory
			cout << "ERROR: memory allocation exhausted\n";
		}
	}
	} // end while()
	//cout << "str: " << (int)str << endl;//
	buffer = str; // copy string
/*
	for (int i=0;i<nchar;++i)
		cout << "str[" << i << "]: " << str[i] << endl;
*/
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
