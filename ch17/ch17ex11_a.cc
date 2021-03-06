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
 *
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

// trying to use make's built-in implicit rules for compilation...
// I think I'm getting somewhere with that..

int main()
try {
	srcfile_info();
	Link* head = new Link("Head");

	cout << "head->value: " << head->value << endl;
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
	if (str_search=head->find("Tail"))
		cout << "found str_search->value: " << str_search->value << endl;
	else
		cout << "String not found in list...\n";
	if (str_search=head->find("cow"))
		cout << "found str_search->value: " << str_search->value << endl;
	else
		cout << "String not found in list...\n";

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
