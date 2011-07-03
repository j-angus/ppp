/**
 * @author Jason Angus
 * @file ch09ex05.c
 * @date 2011-07-03
 *
 * Implement Book class defined in ch09ex05.h
 * g++ -lboost_date_time -Wall -o../bin/"%e" "%f"
 * the "-lboost_date_time" is important to enable compilation with boost date_time library
 */

//#include "../std_lib_facilities.h"
#include "ch09ex05.hpp"

using namespace Library; // for Book class

/**
 * test implementation of Library::Book class
 */
int main()
{
	Book bk;
	try {
		bk.read_isbn();
		bk.read_author();
		bk.read_copyright();
		bk.checkout();
		bk.print();
		bk.checkin();
		bk.print();
	}
	catch (std::runtime_error& e) {
		std::cerr << "runtime error: " << e.what() << std::endl;

		return 1;
	}
	return 0;
}

// default constructor
Book::Book()
	:is_checkedin(false)
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
	std::cout <<	"ISBN:\t" <<get_isbn()<<std::endl<<
				"Author:\t" <<get_author()<<std::endl<<
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
 * read input data and set author for book
 */
void Book::read_author()
{
	std::string str_in; // input from user
	std::cout << "DEBUG: read_author()\n";

	std::cout << "Enter author name: ";
	std::getline(std::cin, str_in);
	//std::cin >> str_in;
	author=str_in;
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
			is_date = true; // if no errors thrown by from_string(), date is good
		} //out_of_range
		catch (std::exception& e) {
			std::cerr << "date error: " << e.what() << std::endl;
			//return 1;
		}
	}
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
