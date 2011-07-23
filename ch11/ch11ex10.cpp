/**
 * @author Jason Angus
 * @file ch11ex10.cpp
 * @date 2011-07-23
 *
 * solution to exercise 11.10 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 *
 * 10. Write a function vector<string> split(const string& s, const string& w)
 * that returns a vector of whitespace-separated substrings from the
 * argument s, where whitespace is defined as "ordinary whitespace" pluS the
 * characters in w.

 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;
using std::stringstream;

#include <vector>
using std::vector;


// returns a vector of whitespace-separated substrings from argument s
// extra split characters in string w
vector<string> split(const string& s, const string& w);

/**
 * Replace punctuation in a string with whitespace.
 */
int main()
{
	cout << "ch11ex10.cpp, solution to exercise 11.10 in PPP\n";
	string line_buf;
	string splitters = ",;:."; // word delimters
	vector<string> words_from_string;

	cout << "Enter a string to break into words:\n";
	getline(cin, line_buf);

	words_from_string = split(line_buf, splitters);

	cout << "Words split up from string:\n";
	for (size_t i=0; i<words_from_string.size(); ++i)
		cout << words_from_string[i] << endl;

	return 0;
} // end main()


// returns a vector of whitespace-separated substrings from argument s
// extra split characters in string w
vector<string> split(const string& s, const string& w)
{
	cout << "DEBUG: split()\n";
	istringstream iss; //(s); // use to split up string s
	vector<string> words; // store words split from string s
	string str_buf; // store words split from s
	string delim_str = s;

	// let's replace w in delim_str with space, then split as usual with iss...
	// simple, and maybe cheating a little, by modifying the string so that
	// iss knows how to split it up the way we want it to. In the book,
	// Stroustrup defines a new class, but I'm not that clever yet...
	for (size_t i=0; i<delim_str.size(); ++i) {
		for (size_t j=0; j<w.size(); ++j) {
			if (delim_str[i]==w[j]) {
				delim_str[i]=' ';
				break;
			}
		}
	}

	iss.str(delim_str);
	while (iss.good()) {
		iss >> str_buf;
		words.push_back(str_buf);
		cout << "iss.rdstate(): " << iss.rdstate() << endl;
		str_buf=""; // clear buffer
	}

	return words;
}
