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

// get Book info from user
Book create_book(); // returns a Book

// get Patron info from user
Patron* get_patron_info(); // returns a Patron

// test drive Book, Patron and Library classes
int main(void)
{
	cout << "ch09ex09.cpp\n";
	std::string str_in; // hold user input

	try {
	Book bk1;
	Patron ptrn1;
	Library lib;
/*
	cout << "Before adding any data to bk1:\n";
	bk1.print();
	// add data to bk1
	bk1.read_isbn();
	bk1.read_title();
	bk1.read_author();
	bk1.read_genre();
	bk1.read_copyright();
	bk1.checkin();

	cout << "After adding data to bk1:\n";
	cout << bk1;

	cout << "Before adding data to ptrn1:\n";
	cout << ptrn1;

	// add data to ptrn1
	cout << "Enter patron name: ";
	getline(cin, str_in);
	std::istringstream iss(str_in);
	std::string fn, ln;
	iss >> fn >> ln;
	ptrn1.set_name(fn, ln);
	iss.clear();
	cout << "Enter the card number: ";
	int cnum; // the card number input
	std::getline(std::cin, str_in);
	iss.str(str_in);
	iss >> cnum;
	ptrn1.set_card_num(cnum);

	cout << "After adding data to ptrn1:\n";
	cout << ptrn1;

	cout << "Before adding any data to library:\n";
	lib.list_books();
	lib.list_patrons();

	// add data to lib
	lib.add_patron(ptrn1);
	lib.add_book(bk1);

	cout << "After adding data to library:\n";
	lib.list_book_titles();
	lib.list_patrons();
*/
	// add a few books to lib
	for (int i=0; i<20; ++i)
		lib.add_book(create_book());
	cout << "After adding a few books to library:\n";
	lib.list_books();

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
	std::stringstream sstream(std::stringstream::in | std::stringstream::out);
	// copyright date of book, set to todays date
	static boost::gregorian::date cpy_date(boost::gregorian::day_clock::local_day());
	static boost::gregorian::date_duration dd(1);
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
	str_cpy_date = boost::gregorian::to_simple_string(cpy_date);

	b.Init(s_isbn, bk_title, fname, lname, g, str_cpy_date, Book::in);

	return b;
}

// get Patron info from user
// returns a Patron
Patron* get_patron_info()
{
	cout << "DEBUG: get_patron_info()\n";
	static Patron p;
	std::string str_in;

	cout << "Enter patron name: ";
	getline(cin, str_in);
	std::istringstream iss(str_in);
	std::string fn, ln;
	iss >> fn >> ln;
	p.set_name(fn, ln);
	iss.clear();
	cout << "Enter the card number: ";
	int cnum; // the card number input
	std::getline(std::cin, str_in);
	iss.str(str_in);
	iss >> cnum;
	iss.clear();
	p.set_card_num(cnum);
	return &p;
}

/*
// error() simply disguises throws:
inline void error(const std::string& s)
{
	throw runtime_error(s);
}
*/
