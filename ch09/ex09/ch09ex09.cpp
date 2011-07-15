/**
 * @author Jason Angus
 * @file ch09ex09.cpp
 * @date 2011-07-14
 *
 * solution to exercise 9.09 PPP
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
 * use -lboost_date_time with g++
 * it is required to enable compilation with boost date_time library
 */

#include <stdexcept>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>

#include <boost/date_time/gregorian/gregorian.hpp> // for date handling


#include "Book.h"
#include "Patron.h"
#include "Library.h"

// create a Book without user input
Book create_book(); // returns a Book

// create a Patron without user input
Patron create_patron(); // returns a Patron

// test drive Book, Patron and Library classes
int main(void)
{
	cout << "ch09ex09.cpp\n";
	std::string str_in; // hold user input

	try {
	Book bk1;
	Patron ptrn1;
	Library lib;

	for (int i=0; i<20; ++i) {
		lib.add_book(create_book());
		lib.add_patron(create_patron());
	}
	cout << "After adding a few books to library:\n";
	lib.list_books();
	lib.list_patrons();

	}
	catch (std::runtime_error& e) {
		std::cerr << "runtime_error: " << e.what() << endl;

		return 1;
	}
	return 0;
}

// create a Book without user input, just using this to test lib funcitons
Book create_book()
{
	cout << "DEBUG: get_book_info()\n";
	static long l_isbn = 1111111111110;
	std::string s_isbn;
	static int title_num = 0;
	std::string bk_title = "Title_";
	std::string fname = "Author";
	std::string lname;
	static Book::Genre g = Book::fiction;
	// use stringstream to convert integers to strings
	std::stringstream sstream(std::stringstream::in | std::stringstream::out);
	namespace bg = boost::gregorian; // for boost date access
	// copyright date of book, set to todays date
	static bg::date cpy_date(bg::day_clock::local_day());
	static bg::date_duration dd(6); // date step size = 6 days
	std::string str_cpy_date;
	static Book b;

	// setup the isbn no.
	++l_isbn;
	++title_num;
	sstream << l_isbn;
	sstream >> s_isbn;
	sstream.str("");
	sstream.clear();

	// setup the title
	sstream << title_num;
	bk_title += sstream.str();

	// setup author name
	lname = "Last_" + sstream.str();
	sstream.clear();
	// set genre
	if (g == Book::children) {
		g = Book::fiction;
	}
	else {
		for (int i=Book::nonfiction; i<=Book::children; ++i) {
			Book::Genre gCurrent = (Book::Genre) i;
			cout << "g: " << g << endl;
			cout << "gCurrent: " << gCurrent << endl;
			if (gCurrent <= g)
				continue;
			g = gCurrent;
			break;
		}
	}

	// set date
	cpy_date = cpy_date + dd;
	str_cpy_date = bg::to_simple_string(cpy_date);

	b.Init(s_isbn, bk_title, fname, lname, g, str_cpy_date, Book::in);

	return b;
}

// create a Patron without user input
Patron create_patron()
{
	cout << "DEBUG: create_patron()\n";
	static Patron p;
	static int pnum = 100; // number of Patron
	static std::string fname = "Patron";
	std::string lname = "Last_";
	std::stringstream sstream(std::stringstream::in | std::stringstream::out);
	static int cnum = 0; // card number
	double fee = 0.0;

	// set unique last name
	sstream << ++pnum;
	lname += sstream.str();

	// next card number
	++cnum;

	// alternate whether patron owes any fees;
	fee = (pnum%3 ? 0.0 : pnum/5.0);
	p.Init(fname, lname, cnum, fee);

	return p;
}

/*
// error() simply disguises throws:
inline void error(const std::string& s)
{
	throw runtime_error(s);
}
*/
