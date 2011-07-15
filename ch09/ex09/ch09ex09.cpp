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
#include <vector>
using std::vector;
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
Book& create_book(Book & b); // returns a Book

// create a Patron without user input
Patron& create_patron(Patron& p); // returns a Patron

// test drive Book, Patron and Library classes
int main(void)
{
	cout << "ch09ex09.cpp\n";
	std::string str_in; // hold user input

	try {
	Book my_book;
	Patron my_patron;
	Library my_library;
	vector<Book> vbook;
	vector<Patron> vpatron;

	// create a bunch of books and patrons
	for (int i=0; i<97; ++i) {
		vbook.push_back(create_book(my_book));
		vpatron.push_back(create_patron(my_patron));
	}

	// add a few books and patrons to library
	size_t i=0;
	size_t j=vbook.size()-1;
	for (; i<vbook.size(); ++i, --j) {
		if (i%3)
			my_library.add_book(vbook[i]);
		if (i%4)
			my_library.add_patron(vpatron[j]);
	}

	// list books and members of library
	cout << "After adding a few books to library:\n";
	my_library.list_books();
	my_library.list_patrons();

	// attempt to check out a bunch of books to a bunch of patrons
	i=0;
	j=vbook.size()-1;
	for (;i<vbook.size(); ++i, --j) {
		my_library.checkout_book(vbook[i],vpatron[j]);
	}

	my_library.list_transactions(); // lists successful checkouts
	my_library.list_who_owes_fees();
	my_library.list_books(); // should show that some books are checked in
							 // and others checked out (successful transactions)

	}
	catch (std::runtime_error& e) {
		std::cerr << "runtime_error: " << e.what() << endl;

		return 1;
	}
	return 0;
}

// create a Book without user input
// just using this to test Library class
Book& create_book(Book & b)
{
	cout << "DEBUG: get_book_info()\n";
	static long l_isbn = 1111111111110; // initial isbn for series of Books
	std::string s_isbn; // isbn is stored as a string within Book
	std::string bk_title = "Title_"; // prefix of Book title
	static int title_num = 0; // initial Book title number for series of Books
	std::string fname = "Author";
	std::string lname;
	static Book::Genre g = Book::fiction;
	// use stringstream to convert integers to strings
	std::stringstream sstream(std::stringstream::in | std::stringstream::out);
	namespace bg = boost::gregorian; // for boost date access
	// copyright date of book, set to todays date
	static bg::date cpy_date(bg::day_clock::local_day());
	static bg::date_duration dd(6); // date step size = 6 days
	std::string str_cpy_date; // store boost::gregorian::date as a string

	// setup the isbn no. as a string ready to store in Book
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

	// setup the genre
	if (g == Book::children) { //last in enum Genre
		g = Book::fiction; // first in enum Genre
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

	// setup date, increment by dd
	cpy_date = cpy_date + dd;
	str_cpy_date = bg::to_simple_string(cpy_date);

	b.Init(s_isbn, bk_title, fname, lname, g, str_cpy_date, Book::in);

	return b;
}

// create a Patron without user input
// just using this to test Library class
Patron& create_patron(Patron & p)
{
	cout << "DEBUG: create_patron()\n";
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
