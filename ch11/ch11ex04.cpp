/**
 * @author Jason Angus
 * @file ch11ex04.cpp
 * @date 2011-07-23
 *
 * solution to exercise 11.03 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 *
 * 4. Write a program that reads strings and for each string outputs the
 * character classification of each character, as defined by the character
 * classificalion functions presented in §11.6. Note that a character can have
 * several classifications (e.g. , x is bOlh a letter and an alphanumeric).
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
#include <iomanip> // for setw()
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include <cctype> // for tolower()
#include <cstdlib> // for exit(), EXIT STATUS...

void classify(char ch); // display charachter type of ch


/**
 * Classify characters in a string.
 */
int main()
{
	cout << "ch11ex04.cpp, solution to exercise 11.02 in PPP\n";
	string line_buf;

	cout << "Enter a string to classify:\n";
	getline(cin, line_buf);

	for (size_t i=0; i<line_buf.size(); ++i)
		classify(line_buf[i]);

	return 0;
} // end main()


// displays the character type of a char
void classify(char ch)
{
	cout << "'" << ch << "' is:\n";
	if (isspace(ch))
		cout << "a space\n";
	if (isalpha(ch))
		cout << "an alpha\n";
	if (isdigit(ch))
		cout << "a digit\n";
	if (isxdigit(ch))
		cout << "a hex digit\n";
	if (isupper(ch))
		cout << "uppercase\n";
	if (islower(ch))
		cout << "lowercase\n";
	if (isalnum(ch))
		cout << "alphanumeric\n";
	if (iscntrl(ch))
		cout << "a control character\n";
	if (ispunct(ch))
		cout << "punctuation\n";
	if (isprint(ch))
		cout << "printable\n";
	if (isgraph(ch))
		cout << "graphical\n";
	return;
}

