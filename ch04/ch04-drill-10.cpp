/**
 * @file ch04-drill-10.cpp
 * @date 2011-06-26
 */


#define QUIT "|" // quit symbol

#include <boost/lexical_cast.hpp>
#include <stdlib.h>
#include <string.h>
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
	string unit;
	vector<double> numbers; // store user input numbers
	bool first_loop = true;
	int num_values = 0;
	double total = 0;

	while (true) {
		cout << "Enter a number (or '|' to quit): ";
		cin >> input;
		if (input == QUIT)
			break;
		cin >> unit;

		if (isdouble(input)) {
			cur_num = atof(input.c_str());
			if (unit == M ) {
				total += cur_num;
				numbers.push_back(cur_num);
			}
			else if (unit == CM) {
				total += (cur_num * 0.01);
				numbers.push_back(cur_num * 0.01);
			}
			else if (unit == FT) {
				total += (cur_num * 0.3048);
				numbers.push_back(cur_num * 0.3048);
			}
			else if( unit == IN) {
				total += (cur_num * 0.0254);
				numbers.push_back(cur_num * 0.0254);
			}
			else {
				cout << "ERROR: no valid unit supplied\n";
				continue;
			}
			++num_values;
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

	cout << "Smallest: " << low << endl;
	cout << "Largest: " << high << endl;
	cout << "Num values entered: " << num_values << endl;
	cout << "Total of values entered: " << total << " m" << endl;
	sort(numbers.begin(), numbers.end());
	for (uint i = 0; i < numbers.size(); ++i)
		cout << "numbers[" << i << "] = " << numbers[i] << " m\n";

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
