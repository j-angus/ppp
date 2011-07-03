/**
 * @author Jason Angus
 * @file ch09ex07.c
 * @date 2011-07-03
 *
 * Implement Book class defined in ch09ex05.h
 * g++ -lboost_date_time -Wall -o../bin/"%e" "%f"
 * the "-lboost_date_time" is important to enable compilation with boost date_time library
 */

//#include "../std_lib_facilities.h"
#include "ch09ex07.hpp"
#include <string>

using namespace Library; // for Book class

/**
 * test implementation of Library::Book class
 */
int main()
{
	Book bk;
	Book bk2;
	try {
		bk.read_title();
		bk.read_author();
		bk.read_genre();
		bk.read_isbn();
		bk.read_copyright();
		bk.checkout();
		bk.print();
		bk.checkin();
		bk.print();
		std::cout << "Is bk != bk2?...." << ((bk!=bk2)? "Yes":"No") <<std::endl;
		std::cout << "Is bk == bk2?...." << ((bk==bk2)? "Yes":"No") <<std::endl;
		std::cout << bk2;
		bk2.print();
		bk2 = bk;
		std::cout << "Is bk != bk2?...." << ((bk!=bk2)? "Yes":"No") <<std::endl;
		std::cout << "Is bk == bk2?...." << ((bk==bk2)? "Yes":"No") <<std::endl;
		std::cout << bk2;
	}
	catch (std::runtime_error& e) {
		std::cerr << "runtime error: " << e.what() << std::endl;

		return 1;
	}
	return 0;
}

// default constructor
Book::Book()
	: isbn13("###"), title("***"), author(2,"***"), is_checkedin(false), genre(unknown)
{
	std::cout << "DEBUG: Book()\n";
}

// member function definitions

// non-modifying operations
/**
 * Display state of book
 */
void Book::print()
{
	std::cout << "DEBUG: print()\n";
	std::cout <<	"Title:\t\t" <<get_title()<<std::endl<<
				"Author:\t\t" <<get_author()<<std::endl<<
				"Genre:\t\t" <<genre_tostring()<<std::endl<<
				"ISBN:\t\t" <<get_isbn()<<std::endl<<
				"Copyright:\t" <<get_copyright()<<std::endl<<
				"Checked in:\t" <<(is_bookin()? "Yes":"No")<<std::endl;
	return;
}

// modifying operations
/**
 * read input data and set isbn number for book
 */
void Book::read_isbn()
{
	bool is_isbn = false; // true when isbn is valid
	std::string str_in; // input from user
	std::cout << "DEBUG: read_isbn()\n";

	while (is_isbn==false) {
		std::cout << "Enter ISBN for book: ";
		std::getline(std::cin, str_in);
		//std::cin >> str_in;
		std::cout << "str_in.size(): " <<str_in.size()<<std::endl;
		if (islong(str_in)) {
			if (str_in.size()==isbn13_length) {
				isbn13 = str_in;
				is_isbn = true;
			}
			else
				std::cout << "Error: ISBN must be " <<isbn13_length<< " digits. Please try again.\n";
		}
		else {
			std::cout << "Error: Invalid isbn. Please try again.\n";
		}
	}
}

/**
 * read input data and set title for book
 */
void Book::read_title()
{
	std::string str_in; // input from user
	std::cout << "DEBUG: read_title()\n";

	std::cout << "Enter book's title: ";
	std::getline(std::cin, str_in);
	title = str_in;
}

/**
 * read input data and set author for book
 */
void Book::read_author()
{
	std::string str_in; // input from user
	std::cout << "DEBUG: read_author()\n";

	std::cout << "Enter author's first name: ";
	std::getline(std::cin, str_in);
	//author.push_back(str_in);
	author[Book::first]=str_in;
	std::cout << "Enter author's last name: ";
	std::getline(std::cin, str_in);
	//author.push_back(str_in);
	author[Book::last]=str_in;
}

/**
 * read input data and set genre for book
 */
void Book::read_genre()
{
	std::string str_in; // input from user
	bool is_genre = false; // true if user enters a valid genre
	while (is_genre == false) {
		std::cout <<	"0.\tFiction\n" << "1.\tNonfiction\n" << "2.\tPeriodical\n" <<
					"3.\tBiography\n" <<"4.\tChildren\n" <<"5.\tUnkown\n";
		std::cout << "Select number coresponding to genre:\n";
		std::getline(std::cin, str_in);
		if (isint(str_in)) {
			switch(atoi(str_in.c_str())) {
			case fiction:
				set_genre(fiction);
				is_genre=true;
				break;
			case nonfiction:
				set_genre(nonfiction);
				is_genre=true;
				break;
			case periodical:
				set_genre(periodical);
				is_genre=true;
				break;
			case biography:
				set_genre(biography);
				is_genre=true;
				break;
			case children:
				set_genre(children);
				is_genre=true;
				break;
			case unknown:
				set_genre(unknown);
				is_genre=true;
				break;
			default:
				std::cout << "Error: Not a valid genre.\n";
			}
		}
		else
			std::cout << "Error: Invalid choice.\n";
	}
	return;
}

/**
 * read input data and set copyright date for book
 */
void Book::read_copyright()
{
	bool is_date = false; // true when user enters a valid date
	std::string str_in; // input from user
	std::cout << "DEBUG: read_copyright()\n";

	while (is_date== false) {
		std::cout << "Enter copyright date (yyyy/mm/dd): ";
		std::getline(std::cin, str_in);
		try {
			copyright = from_string(str_in);
			is_date = true; // if no errors thrown by from_string()h, date is good
		} //out_of_range
		catch (std::exception& e) {
			std::cerr << "date error: " << e.what() << std::endl;
			//return 1;
		}
	}
}

/**
 * return the genre of the book as a string
 */
std::string Book::genre_tostring() const
{
	std::string genre_str;

	switch (get_genre()) {
	case fiction:
		genre_str="Fiction";
		break;
	case nonfiction:
		genre_str="Nonfiction";
		break;
	case periodical:
		genre_str="Periodical";
		break;
	case biography:
		genre_str="Biography";
		break;
	case children:
		genre_str="Children";
		break;
	case unknown:
		genre_str="***";
		break;
	default:
		std::cout << "Error: Not a valid genre\n";
		genre_str="invalid genre";
	}
	return genre_str;
}

// error() simply disguises throws:
inline void error(const std::string& s)
{
	throw std::runtime_error(s);
}

/**
 * @func isint()
 * @param data
 * returns true if DATA represents a valid integer.
 */
bool Library::isint(std::string data)
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;
	bool is_int = true;
	try
	{
		lexical_cast<int>(data);
	}
	catch (bad_lexical_cast &)
	{
		std::cout << "data is not a valid integer\n";
		is_int = false;
	}
	return is_int;
}

/**
 * @func islong()
 * @param data
 * returns true if DATA represents a valid integer.
 */
bool Library::islong(std::string data)
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;
	bool is_long = true;
	try
	{
		lexical_cast<long>(data);
	}
	catch (bad_lexical_cast &)
	{
		std::cout << "data is not a valid long integer\n";
		is_long = false;
	}
	return is_long;
}

// logic operators
bool Library::operator==(const Book& a, const Book& b)
{
	return a.get_isbn()==b.get_isbn();
}

bool Library::operator!=(const Book& a, const Book& b)
{
	//return !(a.get_isbn()==b.get_isbn());
	return !(a==b);
}

// Have a << print out the title, author, and ISBN on separate lines.
std::ostream& Library::operator<<(std::ostream& os, const Book& book)
{
	std::cout <<	"Title:\t" <<book.get_title()<<std::endl<<
			"Author:\t" <<book.get_author()<<std::endl<<
			"Genre:\t" <<book.genre_tostring()<<std::endl<<
			"ISBN:\t" <<book.get_isbn()<<std::endl;
	return os;
 }
