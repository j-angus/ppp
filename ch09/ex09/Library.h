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
 * Have it include a Book, a Patron , and a Date from the chapter.
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
	std::vector<Patron> patron;
	struct Transaction {
		Transaction() : book(), patron(), trans_date() {}
		Book book;
		Patron patron;
		boost::gregorian::date trans_date; // date of transaction
	};
	std::vector<Transaction> transaction;
	bool is_member(Patron p); // checks whether patron is member of the library?
	bool owes_fees(Patron p); // checks whether patron owes fees?
	bool have_book(Book b); // checks whether book is in the library collection?
	void store_transaction(Transaction& t);
	std::vector<std::string> who_owes_fees(); // lists patrons owing fees

public:
	Library();
	void add_patron(Patron p); // adds a member to the library
	void add_book(Book b); // adds a book to the library collection
	void checkout_book(); // allows a patron to checkout a book
	void list_book_titles(); // lists book titles in library collection
	void list_books(); // lists all books and book info in collection
	void list_patrons(); // lists patron members of library
}; // class Library
#endif // LIBRARY_H
