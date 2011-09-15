/**
 * @author Jason Angus
 * @file ch18ex05.cpp
 * @date 2011-09-15
 *
 * 5. Write a function, string cat_dot(const string& s1, const string& s2), that
 *    concatenates two strings with a dot in between. For example, 
 *    cat_dot{"Niels", "Bohr") will return a string containing Niels.Bohr.
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


void srcfile_info(); // display basic source file information
string cat_dot(const string& s1, const string& s2);

int main()
{
	srcfile_info();

	string str1 = "Niels";
	string str2 = "Bohr";
	
	cout << cat_dot(str1, str2) << endl;

	return 0;
}

string cat_dot(const string& s1, const string& s2)
{
	return	s1+"."+s2;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}
