/**
 * @author Jason Angus
 * @file ch11ex05.cpp
 * @date 2011-07-23
 *
 * solution to exercise 11.03 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 *
 * 5 Write a program that replaces punctuation with whitespace.
 * For example, " - don't use the as-if rule." becomes
 * "   don t use the as if rule ".
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cctype> // for tolower()

// replaces punctuation in string s with whitespace
string& replace_punct(string& s);

/**
 * Replace punctuation in a string with whitespace.
 */
int main()
{
	cout << "ch11ex05.cpp, solution to exercise 11.05 in PPP\n";
	string line_buf;

	cout << "Enter a string to classify:\n";
	getline(cin, line_buf);
	cout << "replace_punct() parsed string:\n" << replace_punct(line_buf)
	<< endl;

	return 0;
} // end main()


// replaces punctuation in string s with whitespace
string& replace_punct(string& s)
{
	for (size_t i=0; i<s.size(); ++i)
		if (ispunct(s[i]))
			s[i]=' ';
	return s;
}
