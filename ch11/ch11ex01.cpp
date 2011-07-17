/**
 * @author Jason Angus
 * @file ch11ex01.cpp
 * @date 2011-07-16
 *
 * solution to exercise 11.01 in PPP
 * CHAPTER 11 • CUSTOMIZING INPUT AND OUTPUT
 * 1. Write a program that reads a text file and converts its input to all lower
 * case, producing a new file.
 */

#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <cctype> // for tolower()

int main(int argc, char** argv)
{
	cout << "ch11ex01.cpp, solution to exercise 11.01 in PPP\n";
	vector<string> args; // lets try to store command line args here...
	string temp;

	for (int i=0; i<argc; ++i)
		args.push_back(argv[i]);

	vector<string>::const_iterator it = args.begin();

	while (it!=args.end()) {
		cout << *it << endl;
		temp = *it;
		cout << "temp: " << temp << endl;
		for (size_t i=0; i<temp.size(); ++i)
			cout << (char)tolower(temp[i]);
		cout << endl;

		++it;
	}


	return 0;
}
