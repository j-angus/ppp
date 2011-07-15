/**
 * @author Jason Angus
 * @file Library.cpp
 * @date 2011-07-15
 *
 * this is part of the solution to exercise 9.09 PPP
 * Definition of class Library member functions
 */

#include <iostream>
using std::cout;
using std::endl;
#include "Library.h"

// default constructor
Library::Library()
	: book(), bk_index(0), patron(), transaction()
{
	std::cout << "DEBUG: Library::Library()\n";
}

// adds a member to the library
void Library::add_patron(Patron p)
{
	cout << "DEBUG: Library::add_patron()\n";
	// TODO: need to validate 'p' first
	// if (is_patron(p)) {ok} else {error}
	patron.push_back(p);
}

// adds a book to the library collection
void Library::add_book(Book b)
{
	cout << "DEBUG: Library::add_book()\n";
	// TODO: need to validate 'b' first
	// if (is_book(b)) {ok} else {error}
	book.push_back(b);
}

// allows a patron to checkout a book
void Library::checkout_book(Book& b, Patron& p)
{
	cout << "DEBUG: Library::checkout_book()\n";
	// need a link to the book in the vector<Book> because need to change
	// the state of the book in the Library collection, not the random book
	// being searched for...
	if (have_book(b))
		if (book[bk_index].is_bookin())
			if (is_member(p))
				if (!owes_fees(p)) {
					book[bk_index].checkout();
					store_transaction(book[bk_index],p);
				}
				else
					cout << "Can't loan book - owes fees\n";
			else
				cout << "Can't loan book - not a member\n";
		else
			cout << "Can't loan book - not checked in\n";
	else
		cout << "Can't loan book - not in collection\n";

}

// lists books titles in library collection
void Library::list_book_titles()
{
	cout << "DEBUG: Library::list_book_titles()\n";
	for (size_t i=0; i<book.size(); ++i)
		cout << "Book #" << i << " "<< book[i].get_title() << endl;
}

// lists all books info in library collection
void Library::list_books()
{
	cout << "DEBUG: Library::list_books()\n";
	for (size_t i=0; i<book.size(); ++i)
		cout << book[i] << endl;
}

// lists patron names in library
void Library::list_patron_names()
{
	cout << "DEBUG: Library::list_patrons()\n";
	for (size_t i=0; i<patron.size(); ++i)
		cout << "Patron #" << i << " " << patron[i].get_name() << endl;
}

// lists all patrons info in library
void Library::list_patrons()
{
	cout << "DEBUG: Library::list_patrons()\n";
	for (size_t i=0; i<patron.size(); ++i)
		cout << patron[i] << endl;
}

// private member methods

// returns true if book is in the library
bool Library::have_book(Book& b)
{
	cout << "DEBUG: Library::have_book()\n";
	for (size_t i=0; i<book.size(); ++i)
		if (book[i]==b) {
			bk_index = i;
			return true;
		}
	return false;
}

// returns true if patron is member of the library
bool Library::is_member(Patron& p)
{
	cout << "DEBUG: Library::is_member()\n";
	//cout << " p.get_name()): " << p.get_name() << endl;
	for (size_t i=0; i<patron.size(); ++i) {
		//cout << " patron[i].get_name(): " << patron[i].get_name() << endl;
		if (patron[i]==p)
			return true;
	}
	return false;
}

// returns true if patron owes fees
bool Library::owes_fees(Patron& p)
{
	cout << "DEBUG: Library::owes_fees()\n";
	return p.owes_fees();
}

// stores transaction details
void Library::store_transaction(Book& b, Patron& p)
{
	cout << "DEBUG: Library::store_transaction()\n";
	Transaction t;
	t.book = b;
	t.patron = p;
	namespace bg = boost::gregorian; // for boost date access
	// transaction date of book, set to today's date
	t.date = bg::date(bg::day_clock::local_day());
	transaction.push_back(t);
}

// lists all transaction records
void Library::list_transactions()
{
	cout << "DEBUG: Library::list_transactions()\n";
	for (size_t i=0; i<transaction.size(); ++i)
		cout << "Transaction #" << i << endl
			  << "Transaction Date: "
			  << boost::gregorian::to_simple_string(transaction[i].date) << endl
			  << transaction[i].book << endl
			  << transaction[i].patron << endl;

}

// creates a vector of patrons owing fees
std::vector<std::string> Library::who_owes_fees()
{
	cout << "DEBUG: Library::who_owes_fees()\n";
	std::vector<std::string> owes_fees; // store patrons owing fees

	for (size_t i=0; i<patron.size(); ++i)
		if (patron[i].owes_fees())
			owes_fees.push_back(patron[i].get_name());
	return owes_fees;
}

// lists names of patrons owing fees
void Library::list_who_owes_fees()
{
	cout << "DEBUG: Library::list_who_owes_fees()\n";
	std::vector<std::string> owes_fees = who_owes_fees();

	for (size_t i=0; i<owes_fees.size(); ++i)
		cout << owes_fees[i] << endl;
}
