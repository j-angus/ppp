/**
 * @file ch04-drill-06.cpp
 * @date 2011-06-26
 */


#define QUIT "|" // quit symbol

#include <boost/lexical_cast.hpp>
#include <stdlib.h>
#include "../std_lib_facilities.h"

bool isint(string data);
bool isdouble(string data);

int main()
{

    string input; // user input
    double cur_num; // current number input by user
	double low = 0;
	double high = 0;
	const string M = "m";
	const string CM = "cm";
	const string FT = "ft";
	const string IN = "in";
	//string unit;
	char *cstr_input;
	string unit;
	vector<int> numbers; // store user input numbers
	bool first_loop = true;

	while (true) {
		cout << "Enter a number (or '|' to quit): ";
		cin >> input;
		cin >> unit;
		if (input == QUIT)
			break;
		//strcpy(cstr_input, input.c_str());
		//cstr_input = input.c_str();
		//cur_num = strtod(input.c_str(), &unit);
		//if (unit == input.c_str())
		//	cout << "invalid number\n";
		//else {
		//	cout << "cur_num: " << cur_num << " unit: ";
		//	printf("%s\n", unit);
		//}
		if (isdouble(input)) {
			cur_num = atof(input.c_str());
			if (first_loop) {
				high = cur_num;
				low = high;
				cout << "the largest number so far: " << high << endl;
				first_loop = false;
			}
		}
		else {
			cout << "invalid number\n";
			continue;
		}
		if (cur_num > high) {
			high = cur_num;
			cout << "the largest number so far: " << high << endl;
		}
		else if (cur_num < high && cur_num < low) {
			low = cur_num;
			cout << "the smallest number so far: " << low << endl;
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

/**
 * @func isdouble()
 * @param data
 * returns true if DATA represents a valid double.
 */
bool isdouble(string data)
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;
	bool is_double = true;
	try
	{
		lexical_cast<double>(data);
	}
	catch (bad_lexical_cast &)
	{
		cout << "data is not a valid double.\n";
		is_double = false;
	}
	return is_double;
}
