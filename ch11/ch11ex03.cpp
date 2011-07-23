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
 * prefixes; interprets the numbers correctly; and converts them to decimal
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
#include <iomanip> // for setw()
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include <cctype> // for tolower()
#include <cstdlib> // for exit(), EXIT STATUS...

void show_state(stringstream &ss); // show state of stream
char int_prefix(string& str); // returns type of string 'd', 'o', or 'x'

/**
 * displays and classifies user entered integers.
 */
int main()
{
	cout << "ch11ex03.cpp, solution to exercise 11.02 in PPP\n";
	vector<int> ints_in; // user entered integers
	vector<char> int_type; // x == hex, o == octal, d == decimal
	int int_buf; // temp int storage
	string line_buf;
	vector<string> lines; // temporary string storage
	stringstream ss;

	cout << "Enter a few integers in either octal, decimal or hexadecimal: ";

	while (!cin.eof()) { // quit input with ctl-d
		getline(cin, line_buf);
		if (!cin.eof()) {
			ss.str(line_buf);
			ss.unsetf(std::ios::dec);
			ss.unsetf(std::ios::oct);
			ss.unsetf(std::ios::hex);
			ss >> int_buf;
			cout << "line_buf: " << line_buf << endl;
			cout << "int_buf: " << int_buf << endl;
			show_state(ss);
			if (!ss.fail()) {
				ints_in.push_back(int_buf);
				int_type.push_back(int_prefix(line_buf));
			}
			ss.clear();
			//cout << "After ss.clear:\n";
			//show_state(ss);
		}
	}

	for (size_t i=0; i<ints_in.size(); ++i) {
		switch (int_type[i]) {
		case 'd':
			cout << std::setw(8) << std::dec << std::showbase << ints_in[i]
				<< "\tdecimal\t\tconverts to\t"
				<< std::noshowbase << std::setw(8) << ints_in[i]
				<< "\tdecimal\n";
			break;
		case 'o':
			cout << std::setw(8) << std::oct << std::showbase << ints_in[i]
				<< "\toctal\t\tconverts to\t"
				<< std::dec << std::noshowbase << std::setw(8) << ints_in[i]
				<< "\tdecimal\n";
			break;
		case 'x':
			cout << std::setw(8) << std::hex << std::showbase << ints_in[i]
				<< "\thexidecimal\tconverts to\t"
				<< std::dec << std::noshowbase << std::setw(8) << ints_in[i]
				<< "\tdecimal\n";
			break;
		default:
			break;
		}
		//cout << "ints_in[" << i << "]: " << ints_in[i] << endl;
		//cout << "int_type[" << i << "]: " << int_type[i] << endl;
	}

	return 0;
} // end main()


// show state ofstream
void show_state(stringstream &ss)
{
	cout << "DEBUG: show_state()\n";
	if (ss.eof())
		cout << "eof flag set\n";
	if (ss.fail())
		cout << "fail flag set\n";
	if (ss.bad())
		cout << "bad flag set\n";
	if (ss.good())
		cout << "good flag set\n";
}

// returns type of string 'd', 'o', or 'x'
// assumes that str represents a valid integer
// we could probably use boost::lexical_cast to check for valid int
// then return 'z' to indicate invalid integer type
char int_prefix(string& str)
{
	size_t found; // location of string found within string
	const string oct_prefix = "0";
	const string hexl_prefix = "0x";
	const string hexu_prefix = "0X";

	found = str.find(hexl_prefix);
	if (found!=string::npos)
		return 'x';
	found = str.find(hexu_prefix);
	if (found!=string::npos)
		return 'x';
	found = str.find(oct_prefix);
	if (found!=string::npos) { // number conatains a zero,
							   // but is it the leading character?
		size_t i=0;
		while (isspace(str[i])) ++i; // skip leading whitespace
		if (i==found)
			return 'o';
	}
	return 'd';
}