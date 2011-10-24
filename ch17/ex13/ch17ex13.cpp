/*
 * =============================================================================
 *
 *       Filename:  ch17ex13.cpp
 *
 *    Description: from ppp, page 610
 *
 *        Version:  1.0
 *        Created:  21/10/2011 06:19:52 AM
 *       Revision:  none
 *       Compiler:  g++
 *         Author:  Jason Angus
 *
 * 13. Modify the link class from §17.10.1 to hold a value of a struct God.
 *     struct God should have members of type string: name, mythology, 
 *     vehicle, and weapon. For example, God ("Zeus", "Greek", "", "lightning")
 *     and God ("Odin", "Norse", "Eight-legged flying horse called Slieipner",
 *     ""). Write a print_all function that lists gods with their attributes one
 *     per line. Add a member function add_ordered() that places its new 
 *     element in its correct lexicographical position. Using the Links with the
 *     values of type God, make a list of gods from three mythologies; then move
 *     the elements (gods) from that list to three lexicographically ordered 
 *     lists - one for each mythology.
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

#include "link.h"

void srcfile_info(); // display basic source file information

void print_all(Link* p)
{
	cout << "print_all()\n";
	cout << "{\n";
	while (p) {
		cout << "addr: " << p << ", prev: " << p->previous() << 
			", succ: " << p->next() << endl;
		cout << "name: " << p->god->name << endl; 
		cout << "mythology: " << p->god->mythology << endl;
		cout << "vehicle: " << p->god->vehicle << endl;
		cout << "weapon: " << p->god->weapon << endl;
		p=p->next();
	}
	cout << "}\n";
}

string itostr(int n); // returns string equivalent of integer

int main()
try {
	srcfile_info();

	string link_val = "first";
	Link* stuff = new Link(link_val);
	
	print_all(stuff);
	
	string s1="aaa";
	string s2="bbb";
	string s3="ccc";
	string s4="ddd";

	stuff->add_ordered(new Link(s1));
	
	print_all(stuff);
	
	stuff->add_ordered(new Link(s4));
	stuff->add_ordered(new Link(s2));
	stuff->add_ordered(new Link(s3));

	stuff=stuff->head();
	print_all(stuff);

}
catch (std::exception& e) {
	cout << "standard library exception: " << e.what() << endl; 
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
	string val;
	const int mask = 10; // mask off units
	vector<int> vi;
	
	cout << "checking number: " << n << endl;
	if (n==0) vi.push_back(n);
	while (n>0) {
		vi.push_back(n%mask);
		n/=mask;
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
