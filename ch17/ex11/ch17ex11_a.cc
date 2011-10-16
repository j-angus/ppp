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

string itostr(int n); // returns string equivalent of interger

void int_view(const int n)
// counts number of places in a positive int
// stores each place value into a vector element
{
	cout << "int_view()\n";
	const int mask = 10; // mask off units
	vector<int> vi;
	int p = n;
	
	cout << "checking number: " << n << endl;
	if (n==0) vi.push_back(n);
	while (p%mask) {
		vi.push_back(p%mask);
		p/=mask;
	}	
	cout << "vi.size(): " << vi.size() << endl;
	for (int i=0; i<vi.size(); ++i)
		cout << "vi[" << i << "]: " << vi.at(i) << endl;
}

int main()
try {
	srcfile_info();

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

	string link_num("stuff");
	link_num += ("_" + itostr(1));
	Link* stuff = new Link(link_num);
	print_all(stuff);

	string num;
	cout << "num: " << num << endl;
	int_view(1234);
	int_view(0);
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

string itostr(int n)
// returns string equivalent of a positive interger
{
	cout << "itostr()\n";
	string val("");
	const int mask = 10; // mask off units
	vector<int> vi;
	int p = n;
	
	cout << "checking number: " << n << endl;
	if (n==0) vi.push_back(n);
	while (p%mask) {
		vi.push_back(p%mask);
		p/=mask;
	}	
	for (int i=vi.size()-1; i>=0; --i) {

		switch (vi.at(i)) {
			case 0:
				val+="0";
				break;
			case 1:
				val+="1";
				break;
			case 2:
				val+="2";
				break;
			case 3:
				val+="3";
				break;
			case 4:
				val+="4";
				break;
			case 5:
				val+="5";
				break;
			case 6:
				val+="6";
				break;
			case 7:
				val+="7";
				break;
			case 8:
				val+="8";
				break;
			case 9:
				val+="9";
				break;
			default:
				cout << "itostr(): can't handle n.\n";
				break;
		}
	}
	return val;
}
