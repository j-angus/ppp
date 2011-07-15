/**
 * @author Jason Angus
 * @file Patron.h
 * @date 2011-07-14
 *
 * Declaration of class Patron
 * this is part of the solution to exercise 9.09 PPP
 *
 * 8. Create a Patron class for the library. The class will have a user's name,
 * library card number, and library fees (if owed). Have functions that access
 * these methods, as well as a function to set the fee of the user. Have a
 * helper method that returns a Boolean (bool) depending on whether or
 * not the user owes a fee.
 */

#ifndef PATRON_H
#define PATRON_H
#include <string>

class Patron
{
public:
	Patron(); // default constructor
	// non-modifying functions
	bool has_fee_owing() const {return (fee ? true : false);}
	std::string get_name() const {return first_name + " " + last_name;}
	int get_card_num() const {return card_num;}
	double get_fee() const {return fee;}
	void print();

	// modifying functions
	void set_name(std::string fname, std::string lname);
	void set_first_name(std::string fname);
	void set_last_name(std::string lname);
	void set_card_num(int num);
	void set_fee(double amount);

private:
	std::string first_name;
	std::string last_name;
	int card_num;
	double fee;

}; // class Patron

// overloaded operators
std::ostream& operator<<(std::ostream& os, const Patron& patron);
#endif // PATRON_H
