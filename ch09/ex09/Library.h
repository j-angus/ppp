/**
 * @author Jason Angus
 * @file Library.h
 * @date 2011-07-14
 *
 * this is part of the solution to exercise 9.09 PPP
 *
 * 9. Create a Library class.
 * Include vectors of Books and Patrons.
 * Include a struct called Transaction.
 * Have it include a Book, a Patron, and a Date from the chapter.
 * Make a vector of Transactions.
 * Create functions to add books to the library, add patrons to the library, and
 * check out books.
 * Whenever a user checks out a book, have the library make sure that both the
 * user and the book are in the library. If they aren't, report an error.
 * Then check to make sure that the user owes no fees. If the user does, report
 * an error. If not, create a Transaction, and place it in the vector of
 * Transactions.
 * Also create a method that will return a vector that contains the names of all
 * Patrons who owe fees.
 */

// Declaration of class Library
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <boost/date_time/gregorian/gregorian.hpp> // for date handling
#include "Patron.h"
#include "Book.h"

class Library {
	std::vector<Book> book;
	size_t bk_index; // an index into the book vector
	std::vector<Patron> patron;
	struct Transaction {
		Transaction() : book(), patron(), date() {}
		Book book;
		Patron patron;
		boost::gregorian::date date; // date of transaction
	};
	std::vector<Transaction> transaction;
	// private member methods
	bool have_book(Book& b); // returns true if book is in the library
	bool is_member(Patron& p); // returns true if patron is member of the library
	bool owes_fees(Patron& p); // returns true if patron owes fees
	void store_transaction(Book& b, Patron& p);
	std::vector<std::string> who_owes_fees(); // creates a vector of
											  // patrons owing fees

public:
	// modifying methods
	Library(); // default contructor
	void add_patron(Patron p); // adds a member to the library
	void add_book(Book b); // adds a book to the library collection
	void checkout_book(Book& b, Patron& p); // attempts to checkout a book
	// non-modifying methods
	void list_book_titles(); // lists book titles in library collection
	void list_books(); // lists all books and book info in collection
	void list_patron_names(); // lists names of library patrons
	void list_patrons(); // lists all patrons and patron info in library
	void list_transactions(); // lists all transaction records
	void list_who_owes_fees(); // lists names of patrons owing fees
}; // class Library

#endif // LIBRARY_H
