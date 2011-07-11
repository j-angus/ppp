/**
 * @file patron.cpp
 * @date 2011-07-11
 *
 * Implementation of Patron class
 */

#include <iostream> // for cout
#include "patron.hpp"

// default constructor
Patron::Patron()
	: first_name("first"), last_name("last"), card_num(0), fee(0.0)
{
	std::cout << "DEBUG: Patron() default constructor\n\n";
}

// modifying functions
void Patron::set_name(std::string fname, std::string lname)
{
	first_name = fname;
	last_name = lname;
}

void Patron::set_first_name(std::string fname)
{
	first_name = fname;
}

void Patron::set_last_name(std::string lname)
{
	last_name = lname;
}

void Patron::set_card_num(int num)
{
	card_num = num;
}

void Patron::set_fee(double amount)
{
	fee = amount;
}

void Patron::show()
{
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
	std::cout << "Patron info:\n"
			  << first_name + " " + last_name << std::endl
			  << "card number: " << card_num << std::endl
			  << "fees owing: $" << fee << std::endl;
}
