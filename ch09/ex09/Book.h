/**
* @author Jason Angus
* @file Book.h
* @date 2011-07-03
*
* Declaration of class Book
*
* Create an enumerated type for the Book class called Genre.
* Have the types be fiction, nonfiction, periodical, biography, children.
* Give each book a Genre and make appropriate changes to the Book
* constructor and member functions.
*/

// prevent multiple inclusions of header file
#ifndef BOOK_H
#define BOOK_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <boost/date_time/gregorian/gregorian.hpp> // for date handling
#include <boost/lexical_cast.hpp> // convert c++ string

using namespace boost::gregorian; // for date class and to_simple_string(date d)

class Book {
public:
	// non-modifying operations
	Book(); // default constructor
	enum Genre {fiction, nonfiction, periodical, biography, children,unknown};
	string get_isbn() const {return isbn13;}
	string get_title() const {return title;}
	//string get_author() const {return author[Book::first] + " " + author[Book::last];}
	string get_author() const {return author_first_name + " " + author_last_name;}
	Genre get_genre() const {return genre;}
	string genre_tostring() const; // return the genre as a string
	string get_copyright() {return boost::gregorian::to_simple_string(copyright);}
	bool is_bookin() const {return is_checkedin;}
	void print();

	// modifying operation
	void read_isbn();
	void read_title();
	void read_author();
	void set_author_name(string first, string last);

	void read_genre();
	void set_genre(Genre g) {genre = g;}
	void read_copyright();
	void checkout() {cout << "DEBUG: checkout()\n";is_checkedin=false;}
	void checkin() {cout << "DEBUG: checkin()\n";is_checkedin=true;}

private:
	string isbn13; // size must be 13 char long, no more, no less
	static const uint isbn13_length=13;
	string title;
	enum Name {first, last} name;
	//string author;
	vector<string> author;
	string author_first_name;
	string author_last_name;
	boost::gregorian::date copyright; // copyright date of book
	bool is_checkedin;
	Genre genre;

}; // end class Book

// overloaded operators
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& book);

// helper functions
/**
* returns true if string represents an integer
*/
bool isint(string data);

/**
* returns true if string represents a valid long integer
*/
bool islong(string data);
#endif
