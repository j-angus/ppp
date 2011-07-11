/**
 * @file ch09ex08.cpp
 * @date 2011-07-11
 *
 * test drive implementation of Patron class
 */

#include <cstdlib> // for EXIT_SUCCESS
#include <iostream> // for cout, endl
#include "patron.hpp"

int main(void)
{
	std::cout << "ppp: ch09ex08, test drive implementation of Patron class\n\n";

	Patron myPatron;

	myPatron.show();
	std::cout << "Patron has fees? "
			  << (myPatron.has_fee_owing() ? "true" : "false") << std::endl;

	myPatron.set_name("Howlong", "Goodone");
	myPatron.set_card_num(123456789);
	myPatron.set_fee(141.32);

	myPatron.show();
	std::cout << "Patron has fees? "
			  << (myPatron.has_fee_owing() ? "true" : "false") << std::endl;

	exit(EXIT_SUCCESS);
}
