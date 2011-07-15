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
	: book(), patron(), transaction()
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
void Library::checkout_book(Book b, Patron p)
{
	cout << "DEBUG: Library::checkout_book()\n";
}

// lists books in library collection
void Library::list_book_titles()
{
	cout << "DEBUG: Library::list_book_titles()\n";
	for (size_t i=0; i<book.size(); ++i)
		cout << "Book #" << i << " "<< book[i].get_title() << endl;
}

// lists books in library collection
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

// lists patron names in library
void Library::list_patrons()
{
	cout << "DEBUG: Library::list_patrons()\n";
	for (size_t i=0; i<patron.size(); ++i)
		cout << patron[i] << endl;
}

// allow a patron to checkout a book
// if book exists and is not checked out AND
// patron is a member of the library AND
// the patron does not owe any fees:
// allow patron to check out the book, add transacton to transaction vector
// pnum: patron membership num
// isbn: isbn number of book
//void Library::checkout_book(Book b, Patron p)
//{
	// is book in library?
	// is book checked in?
	// is patron a member of library?
	// does patron owe any fees?
	// if all good, create a transaction
	// book, patron, date
	// add to transaction vector
	// find book
	/*
	std::stringstream ss(std::stringstream::in | std::stringstream::out);
	std::string str_isbn; // store converted isbn number
	bool have_book = false;
*/
	// create below functions to allow this logic to occurr,
	// function prototypes already in Book.h file
	/* if (have_book(Book b)) // compare isbn values
	 * 	if (is_member(Patron p)) // compare card num values
	 * 		if (!owes_fees(Patron p)) // check p's fees balance
	 * 			store_transaction(Book b, Patron p))
	 */

/*
	//ss << isbn;
	//ss >> str_isbn;
	for (size_t i = 0; i < book.size(); ++i) {
		if (book[i].get_isbn() == str_isbn) {
		}
	}
*/
//}
