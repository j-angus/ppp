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
void Library::checkout_book()
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

// lists patron members of library
void Library::list_patrons()
{
	cout << "DEBUG: Library::list_patrons()\n";
	for (size_t i=0; i<patron.size(); ++i)
		cout << "Patron #" << i << " " << patron[i].get_name() << endl;
}
