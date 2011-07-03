/**
 * @author Jason Angus
 * @file ch09ex07.h
 * @date 2011-07-03
 *
 * Create an enumerated type for the Book class called Genre.
 * Have the types be fiction, nonfiction, periodical, biography, children.
 * Give each book a Genre and make appropriate changes to the Book
 * constructor and member functions.

 */

#include <boost/date_time/gregorian/gregorian.hpp> // for date handling
#include <boost/lexical_cast.hpp> // convert c++ string

using namespace boost::gregorian; // for date class and to_simple_string(date d)

namespace Library {

class Book {
	public:
		// non-modifying operations
		Book(); // default constructor
		enum Genre {fiction, nonfiction, periodical, biography, children,unknown};
		std::string get_isbn() const {return isbn13;}
		std::string get_title() const {return title;}
		std::string get_author() const {return author[Book::first] + " " + author[Book::last];}
		Genre get_genre() const {return genre;}
		std::string genre_tostring() const; // return the genre as a string
		std::string get_copyright() {return boost::gregorian::to_simple_string(copyright);}
		bool is_bookin() const {return is_checkedin;}
		void print();

		// modifying operation
		void read_isbn();
		void read_title();
		void read_author();
		void read_genre();
		void set_genre(Genre g) {genre = g;}
		void read_copyright();
		void checkout() {std::cout << "DEBUG: checkout()\n";is_checkedin=false;}
		void checkin() {std::cout << "DEBUG: checkin()\n";is_checkedin=true;}

	private:
	/**
	 * Does the ISBN-13 have any meaning imbedded in the numbers?
	 * The five parts of an ISBN are as follows:
	 *	1. The current ISBN-13 will be prefixed by "978"
	 *	2. Group or country identifier which identifies a national or geographic grouping of publishers;
	 *	3. Publisher identifier which identifies a particular publisher within a group;
	 *	4. Title identifier which identifies a particular title or edition of a title;
	 *	5. Check digit is the single digit at the end of the ISBN which validates the ISBN.
	 */
		//char *isbn13[isbn13_length+1]; // a null terminated c-string of 13 characters
		// or
		std::string isbn13; // size must be 13 char long, no more, no less
		static const uint isbn13_length=13;
		std::string title;
		enum Name {first, last}name;
		//std::string author;
		std::vector<std::string> author;
		boost::gregorian::date copyright; // copyright date of book
		bool is_checkedin;
		Genre genre;

};

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
} // Library
