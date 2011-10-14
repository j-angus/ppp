/**
 * @author Jason Angus
 * @file ch18ex06.cpp
 * @date 2011-09-15
 *
 * 6. Modify cat_dot() from the previous exercise to take a string to be used as
 *    the separator (rather than dot) as its third argument.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


void srcfile_info(); // display basic source file information
string cat_dot(const string& s1, const string& s2, const string& sep);

int main()
{
	srcfile_info();

	string str1 = "Niels";
	string str2 = "Bohr";
	string sep1 = "_";

	cout << cat_dot(str1, str2, sep1) << endl;

	return 0;
}

string cat_dot(const string& s1, const string& s2, const string& sep)
{
	return	s1+sep+s2;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}
