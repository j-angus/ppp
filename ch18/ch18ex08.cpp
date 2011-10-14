/**
 * @author Jason Angus
 * @file ch18ex08.cpp
 * @date 2011-10-01
 *
 * 8. Rewrite all the functions in §18.6 to use the approach of making a 
 *    backward copy of the string and then comparing; for example, take "home",
 *    generate "emoh", and compare those two strings to see that they are 
 *    different, so home isn't a palindrome.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


void srcfile_info(); // display basic source file information

string str_rev(string& str); // reverse the given string
int str_cmp(string& str1, string& str2); // compare two strings
// test strings for being a palindrome
bool is_palindrome(string& str); 

int main()
{
	srcfile_info();
	
	string tst="a test";
	string s1="abcd";
	string s2="dcba";
	string s3="aabbdbbaa";
	string s4="aabbcbbaa";

	cout << str_rev(tst) << endl;
	cout << str_cmp(s1,s2) << endl;
	cout << str_cmp(s1,s1) << endl;
	cout << str_cmp(s2,s1) << endl;
	cout << str_cmp(s2,s1) << endl;
	cout << str_cmp(s3,s4) << endl;
	cout << str_cmp(s4,s3) << endl;

	cout << (is_palindrome(s1) ? "true" : "false") << endl;
	cout << (is_palindrome(s3) ? "true" : "false") << endl;
	return 0;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

// reverse the given string
string str_rev(string& str)
{
	cout << "str_rev()\n";
	cout << "str: " << str << endl;
	string rstr; // the reversed string
	for (int i=str.size()-1; i>=0; --i)
		rstr.push_back(str[i]);

	return rstr;

}

// compare two strings
int str_cmp(string& str1, string& str2)
{
	cout << "str_cmp(): " << str1 << ", " << str2 << endl;
	int i=0;

	while (i<str1.size() && i<str2.size()) {
		if (str1[i]!=str2[i]) {
			cout << "i: " << i << endl;
			cout << "str1[" << i << "]: " << str1[i] << endl;
			cout << "str2[" << i << "]: " << str2[i] << endl;
			return str1[i]-str2[i];
		}
		++i;
	}
	return 0;
}

// test strings for being a palindrome
bool is_palindrome(string& str)
{
	cout << "is_palindrome()\n";
	cout << "str: " << str << endl;
	string rstr=str_rev(str);
	return ((str_cmp(str, rstr)) ? false : true);

}
