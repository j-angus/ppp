/**
 * @author Jason Angus
 * @file ch11ex09.cpp
 * @date 2011-07-23
 *
 * solution to exercise 11.03 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 *
 * 9. Write a function vector<string> split(const string& s) that returns a
 * vector of whitespace-separated substrings from the argument s.
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
vector<string> split(const string& s);

/**
 * Replace punctuation in a string with whitespace.
 */
int main()
{
	cout << "ch11ex09.cpp, solution to exercise 11.05 in PPP\n";
	string line_buf;
	vector<string> words_from_string;

	cout << "Enter a string to break into words:\n";
	getline(cin, line_buf);

	words_from_string = split(line_buf);

	cout << "Words split up from string:\n";
	for (size_t i=0; i<words_from_string.size(); ++i)
		cout << words_from_string[i] << endl;

	return 0;
} // end main()


// returns a vector of whitespace-separated substrings from argument s
vector<string> split(const string& s)
{
	cout << "DEBUG: split()\n";
	istringstream iss(s); // use to split up string s
	vector<string> words; // store words split from string s
	string str_buf; // store words split from s

	while (iss.good()) {
		iss >> str_buf;
		words.push_back(str_buf);
		cout << "iss.rdstate(): " << iss.rdstate() << endl;
	}

	return words;
}
