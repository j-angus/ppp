/**
 * @file ch04ex04.cpp
 * @date 2011-06-26
 *
 * Guess the number a user selects between 1 and 100
 */


#define QUIT "|" // quit symbol

#include <boost/lexical_cast.hpp>
#include <stdlib.h>
#include <string.h>
#include "../std_lib_facilities.h"

int main()
{

	string reply; // user's response to our questions
	const string Y = "y";
	const string N = "n";
	const int MAX_GUESS = 7; // maximum number of guesses allowed
	int guess = 50; // program's attempt at guessing user's number
	int up_bound = 100;
	int low_bound = 0;
	int num_guess = 0; // count the number of times we guess

	cout << "Think of a number between 1 and 100 then answer my questions to see if I can get it\n";
	while (num_guess++ <= MAX_GUESS) {
		cout << "Is your number less than " << guess << "? [y/n]: ";
		cin >> reply;
		if (reply == Y) {
			up_bound = guess;
			guess = low_bound + ((up_bound - low_bound) / 2);
			if (up_bound - low_bound == 1) {
				cout << "your number is: " << guess << endl;
				break;
			}
		}
		else {
			low_bound = guess;
			guess = low_bound + ((up_bound - low_bound) / 2);
		}
		// cout << "low_bound: "<< low_bound << endl;
		// cout << "up_bound: " << up_bound << endl;
		if (up_bound - low_bound == 1) {
			cout << "your number is: " << guess << endl;
			break;
		}
	}

	// cout << "guess: " << guess << endl;

	return 0;
}
