/**
 * @author Jason Angus
 * @file patron.cpp
 * @date 2011-07-14
 *
 * Implementation of Patron class
 * this is part of the solution to exercise 9.09 PPP
 */

#include <iostream>
using std::cout;
using std::endl;

//#include <iomanip>
#include <string>
#include "Patron.h"

// default constructor
Patron::Patron()
	: first_name("first_name"), last_name("last_name"), card_num(0), fee(0.0)
{
	cout << "DEBUG: Patron::Patron()\n";
}

// modifying functions
void Patron::set_name(std::string fname, std::string lname)
{
	cout << "DEBUG: Patron::set_name()\n";
	first_name = fname;
	last_name = lname;
}

void Patron::set_first_name(std::string fname)
{
	cout << "DEBUG: Patron::set_first_name()\n";
	first_name = fname;
}

void Patron::set_last_name(std::string lname)
{
	cout << "DEBUG: Patron::set_last_name()\n";
	last_name = lname;
}

void Patron::set_card_num(int num)
{
	cout << "DEBUG: Patron::set_card_num()\n";
	// TODO: num must be a valid int, check before assignment
	card_num = num;
}

void Patron::set_fee(double amount)
{
	cout << "DEBUG: Patron::set_fee()\n";
	fee = amount;
}

// set all private data in one function
void Patron::Init(std::string fn, std::string ln, int cnum, double fee)
{
	set_name(fn,ln);
	set_card_num(cnum);
	set_fee(fee);
}

void Patron::print()
{
	cout << "DEBUG: Patron::print()\n";
	cout.setf(std::ios::fixed, std::ios::floatfield);
	cout.setf(std::ios::showpoint);
	cout.precision(2);
	cout << "Patron info:\n"
		 << first_name + " " + last_name << endl
		 << "card number: " << card_num << endl
		 << "fees owing: $" << fee << endl;
}

// overloaded operators
std::ostream& operator<<(std::ostream& os, const Patron& patron)
{
	cout.setf(std::ios::fixed, std::ios::floatfield);
	cout.setf(std::ios::showpoint);
	cout.precision(2);
	cout << "Patron info:\n"
		 << "Name:\t\t" << patron.get_name() << endl
		 << "Card number:\t" << patron.get_card_num() << endl
		 << "Fees owing:\t$" << patron.get_fee() << endl;
	return os;
}
