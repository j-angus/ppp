/*
 * =============================================================================
 *
 *       Filename:  ch17ex11_a.cc
 *
 *    Description: from ppp, page 610
 *
 *        Version:  1.0
 *        Created:  10/13/2011 06:19:52 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jason Angus
 *	TODO:	come up with a method to create dynamic values for list
 *		so i can make it arbitrarily sized and see how values
 *		are affected
 * =============================================================================
 */

#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
#include<stdexcept>
#include<vector>
using std::vector;
#include<string>
using std::string;

#include "link_a.h"

void srcfile_info(); // display basic source file information

void print_all(Link* p)
{
	cout << "print_all()\n";
	cout << "{\n";
	while (p) {
		cout << p->value << ":\taddr: " << p << ", prev: " << p->previous() 
			<< ", succ: " << p->next() << endl;
		p=p->next();
	}
	cout << "}\n";
}

int main()
try {
	srcfile_info();
	/*
	Link* head = new Link("Head");
	print_all(head);
	cout << "head->value: " << head->value << endl;
	*/

	Link* numbers = new Link("ONE");
	numbers = numbers->insert(new Link("TWO"));
	numbers = numbers->insert(new Link("THREE"));
	numbers = numbers->insert(new Link("FOUR"));
	numbers = numbers->insert(new Link("FIVE"));
	print_all(numbers);

	numbers = numbers->erase();
	print_all(numbers);

	numbers = numbers->find("ONE");
	print_all(numbers);
	numbers = numbers->erase();
	print_all(numbers);

	numbers = numbers->advance(-2);
	print_all(numbers);

/*
	cout << "address of head: " << &head << endl;

	Link* tail = new Link("Tail");
	head->add(tail);
	cout << "head->next()->value: " << head->next()->value << endl;
	cout << "address of head->next(): " << (head->next()) << endl;

	Link* next_link = new Link("next_link");
	head->add(next_link);
	cout << "head->next()->next()->value: " << head->next()->value << endl;
	cout << "address of head->next(): " << head->next() << endl;

	head=head->erase();
	cout << "after head=head->erase() ...\n";
	cout << "head->value: " << head->value << endl;
	cout << "address of head: " << &head << endl;

	Link* str_search=0;
	if ((str_search=head->find("Tail")))
		cout << "found str_search->value: " << str_search->value << endl;
	else
		cout << "String not found in list...\n";
	if ((str_search=head->find("cow")))
		cout << "found str_search->value: " << str_search->value << endl;
	else
		cout << "String not found in list...\n";
	*/

}
catch (std::exception& e) {
	cout << "standard library exception: " << e.what() << "\n";
}
catch (...) {
	cerr << "unknown exception thrown\n";
}


void srcfile_info()
{
	cout << "srcfile_info()\n";
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}
