/**
 * @author Jason Angus
 * @file ch09ex09.cpp
 * @date 2011-07-14
 *
 * 9. Create a Library class. Include vectors of Books and Patrons. Include a
 * struct called Transaction. Have it include a Book, a Patron , and a Date
 * from the chapter. Make a vector of Transactions. Create functions to add
 * books to the library, add patrons to the library, and check out books.
 * Whenever a user checks out a book, have the library make sure that both the
 * user and the book are in the library. If they aren't, report an error.
 * Then check to make sure that the user owes no fees. If the user does, report
 * an error. If not, create a Transaction, and place it in the vector of
 * Transactions. Also create a method that will return a vector that contains
 * the names of all Patrons who owe fees.
 *
 * g++ -lboost_date_time -Wall -o../bin/"%e" "%f"
 * the "-lboost_date_time" is important to enable compilation with  the
 * boost date_time library
 */

#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Book.h"
#include "Patron.h"

int main(void)
{
	cout << "ch09ex09.cpp\n";

	try {
	Book bk1;
	Patron ptrn1;
	}
	catch (runtime_error& e) {
		std::cerr << "runtime error: " << e.what() << endl;

		return 1;
	}
	return 0;
}

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}
