/**
* @author Jason Angus
* @file Book.h
* @date 2011-07-14
*
* Declaration of class Book
* solution to exercise 9.09 PPP
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
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp> // for date handling

class Book {
public:

	// non-modifying operations
	Book(); // default constructor
	enum Genre {fiction, nonfiction, periodical, biography, children, unknown};
	enum Book_status {out, in};
	std::string get_isbn() const {return isbn13;}
	std::string get_title() const {return title;}
	std::string get_author() const {return author_fname + " " + author_lname;}
	Genre get_genre() const {return genre;}
	std::string genre_tostring() const; // return the genre as a string
	std::string get_copyright_date() const;
	bool is_bookin() const {return is_checkedin;}
	void print();
	// initialise all parameters:
	void Init(std::string isbn, std::string title,
			std::string fn, std::string ln,
			Genre g, std::string cpy_date, Book_status s);

	// modifying operations
	void read_isbn();
	bool set_isbn(std::string n);
	void read_title();
	void set_title(std::string t) {cout << "DEBUG: Book::set_title()\n";title=t;}
	void read_author();
	void set_author(std::string fname, std::string lname);
	void read_genre();
	void set_genre(Genre g) {cout << "DEBUG: Book::set_genre()\n";genre = g;}
	void read_copyright();
	bool set_copyright_date(std::string date);
	void checkout();
	void checkin();

private:
	std::string isbn13; // size must be 13 char long, no more, no less
	static const uint isbn13_length=13;
	std::string title;
	std::string author_fname;
	std::string author_lname;
	boost::gregorian::date copyright_date; // copyright date of book
	Genre genre;
	bool is_checkedin;

}; // class Book

// overloaded operators
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
std::ostream& operator<<(std::ostream& os, const Book& book);

// helper functions
/**
* returns true if string represents an integer
*/
bool isint(std::string data);

/**
* returns true if string represents a valid long integer
*/
bool islong(std::string data);
#endif // BOOK_H
