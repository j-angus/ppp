/**
 * @file ch04-drill-02.cpp
 * @date 2011-06-26
 */


#define QUIT "|" // quit symbol

#include <boost/lexical_cast.hpp>
#include "../std_lib_facilities.h"

bool isint(string data);

int main()
{

    string input;
	int num1;
	int num2; // user input
	vector<int> numbers; // store user input numbers
	string choice; // get user's decsion to finish

	while (choice != QUIT) {
		cout << "Enter two integers (or '|' to quit): ";
		cin >> input;
		if (input == QUIT)
			break;
		if (isint(input))
			num1 = atoi(input.c_str());
		else
			continue;
        cin >> input;
        if (input == QUIT)
			break;
		if (isint(input))
			num2 = atoi(input.c_str());
		else
			continue;


		if (num1 < num2) {
			cout << "the smaller value is: " << num1 << endl;
			cout << "the larger value is: "<< num2 << endl;
		}
		else {
			cout << "the smaller value is: " << num2 << endl;
			cout << "the larger value is: "<< num1 << endl;
		}
	}

	return 0;
}


/**
 * @func isint()
 * @param data
 * returns true if DATA represents a valid integer.
 */
bool isint(string data)
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;
	bool is_int = true;
	try
	{
		lexical_cast<int>(data);
	}
	catch (bad_lexical_cast &)
	{
		cout << "data is not a valid integer\n";
		is_int = false;
	}

	return is_int;
}
