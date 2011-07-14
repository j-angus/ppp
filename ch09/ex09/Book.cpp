/**
 * @author Jason Angus
 * @file Book.cpp
 * @date 2011-07-14
 *
 * Implement Book class member functions
 * g++ -lboost_date_time -Wall -o../bin/"%e" "%f"
 * the "-lboost_date_time" is important to enable compilation with boost
 * date_time library
 */

//#include "../std_lib_facilities.h"
#include "Book.h"
#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include <stdexcept>
using std::exception;

//#include <ios_base>

// default constructor
Book::Book()
	: isbn13("###"),
	  title("***"),
	  author(2,"***"),
	  is_checkedin(false),
	  genre(unknown)
{
	std::cout << "DEBUG: Book(), default constructor\n";
}

// member function definitions

// non-modifying operations
/**
 * Display state of book
 */
void Book::print()
{
	cout << "DEBUG: print()\n";
	cout << "Title:\t\t" <<get_title()<<endl<<
			"Author:\t\t" <<get_author()<<endl<<
			"Genre:\t\t" <<genre_tostring()<<endl<<
			"ISBN:\t\t" <<get_isbn()<<endl<<
			"Copyright:\t" <<get_copyright()<<endl<<
			"Checked in:\t" <<(is_bookin()? "Yes":"No")<<endl;
	return;
}

// modifying operations
/**
 * read input data and set isbn number for book
 */
void Book::read_isbn()
{
	bool is_isbn = false; // true when isbn is valid
	string str_in; // input from user
	cout << "DEBUG: read_isbn()\n";

	while (is_isbn==false) {
		cout << "Enter ISBN for book: ";
		getline(cin, str_in);
		//cin >> str_in;
		cout << "str_in.size(): " <<str_in.size()<<endl;
		if (islong(str_in)) {
			if (str_in.size()==isbn13_length) {
				isbn13 = str_in;
				is_isbn = true;
			}
			else
				cout << "Error: ISBN must be " <<isbn13_length
					 << " digits. Please try again.\n";
		}
		else {
			cout << "Error: Invalid isbn. Please try again.\n";
		}
	}
}

/**
 * read input data and set title for book
 */
void Book::read_title()
{
	string str_in; // input from user
	cout << "DEBUG: read_title()\n";

	cout << "Enter book's title: ";
	getline(cin, str_in);
	title = str_in;
}

/**
 * read input data and set author for book
 */
void Book::read_author()
{
	string str_in; // input from user
	cout << "DEBUG: read_author()\n";

	cout << "Enter author's first name: ";
	getline(cin, str_in);
	//author.push_back(str_in);
	author[Book::first]=str_in;
	cout << "Enter author's last name: ";
	getline(cin, str_in);
	//author.push_back(str_in);
	author[Book::last]=str_in;
}

/**
 * read input data and set genre for book
 */
void Book::read_genre()
{
	string str_in; // input from user
	bool is_genre = false; // true if user enters a valid genre
	while (is_genre == false) {
		cout << "0.\tFiction\n"
			  << "1.\tNonfiction\n"
			  << "2.\tPeriodical\n"
			  << "3.\tBiography\n"
			  << "4.\tChildren\n"
			  << "5.\tUnkown\n";
		cout << "Select number coresponding to genre:\n";
		getline(cin, str_in);
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
				cout << "Error: Not a valid genre.\n";
			}
		}
		else
			cout << "Error: Invalid choice.\n";
	}
	return;
}

/**
 * read input data and set copyright date for book
 */
void Book::read_copyright()
{
	bool is_date = false; // true when user enters a valid date
	string str_in; // input from user
	cout << "DEBUG: read_copyright()\n";

	while (is_date== false) {
		cout << "Enter copyright date (yyyy/mm/dd): ";
		getline(cin, str_in);
		try {
			copyright = from_string(str_in);
			is_date = true; // if no errors thrown by from_string()h, date is good
		} //out_of_range
		catch (exception& e) {
			cerr << "date error: " << e.what() << endl;
			//return 1;
		} // exception
	}
}

/**
 * return the genre of the book as a string
 */
string Book::genre_tostring() const
{
	string genre_str;

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
		cout << "Error: Not a valid genre\n";
		genre_str="invalid genre";
	}
	return genre_str;
}

/**
 * isint():
 * @param data
 * returns true if DATA represents a valid integer.
 */
bool isint(string data)
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
		cout << "data is not a valid integer\n";
		is_int = false;
	}
	return is_int;
}

/**
 * @func islong()
 * @param data
 * returns true if DATA represents a valid integer.
 */
bool islong(string data)
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
		cout << "data is not a valid long integer\n";
		is_long = false;
	}
	return is_long;
}

// logic operators
bool operator==(const Book& a, const Book& b)
{
	return a.get_isbn()==b.get_isbn();
}

bool operator!=(const Book& a, const Book& b)
{
	//return !(a.get_isbn()==b.get_isbn());
	return !(a==b);
}

// Have a << print out the title, author, and ISBN on separate lines.
ostream& operator<<(ostream& os, const Book& book)
{
	cout << "Title:\t"  << book.get_title() << endl
		 << "Author:\t" << book.get_author() << endl
		 << "Genre:\t"  << book.genre_tostring() << endl
		 << "ISBN:\t"   << book.get_isbn() << endl;
	return os;
}
