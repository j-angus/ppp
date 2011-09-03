/**
 * @author Jason Angus
 * @file ch17ex11.cpp
 * @date 2011-08-28
 *
 * 11. Complete the "list of gods" example from §17.1O.1 and run it.
 */

//#include "../std_lib_facilities.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

void srcfile_info(); // display basic source file information

class Link {
public:
	string value;
	Link(const string& v, Link* p = 0, Link* s = 0)
	: value(v), prev(p), succ(s) {cout << "Link::Link(), value: " << v << "\n";}
	Link* insert(Link* n);			// insert n before this object
	Link* add(Link* n); 			// insert n after this object
	Link* erase(); 					// remove this object from list
	Link* find(const string& s); 	// find s in list
	const Link* find (const string& s) const; // find s in list
	Link* advance(int n); 			// move n positions in list
	Link* next() const { return succ; }
	Link* previous() const { return prev; }

private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n) // insert n before this object; return n
{
	cout << "Link::insert()\n";
	if (n==0) return this;
	if (this==0) return n;
	n->succ = this; // this object comes after n
	if (prev) prev->succ = n;
	n->prev = prev; // this object's predecessor becomes n's predecessor
	prev = n;		// n becomes this object's predecessor
	return n;
}

Link* Link::add(Link* n) // insert n after this object
{
	cout << "Link::add()\n";
	// similar to insert()
	if (n==0) return this;
	if (this==0) return n;
	n->prev = this; // n comes after this object
	if (succ) succ->prev = n;
	n->succ = succ; // this object's successor becomes n's successor
	succ = n;		// n becomes this object's successor
	return n;
}

Link* Link::erase() // remove this object from list
{
	cout << "Link::erase()\n";
	if (this==0) return 0;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;
}

Link* Link::find(const string& s) // find s in list, return 0 for not found
{
	cout << "Link::find()\n";
	cout << "searching for: \"" << s << "\"\n";
	Link* p = this;
	// rewind to beginning of list
	while (p->prev)
		p=p->prev;
	while (p) {
		if (p->value == s) {
			cout << "found\n";
			return p;
		}
		cout << "p->value: \"" << p->value << "\", still searching\n";
		p = p->succ ;
	}
	cout << "\"" << s << "\"not found...\n";
	return 0;
}

Link* Link::advance(int n) // move n positions in list, return 0 for "not found"
	// posi1ive n moves forward, negative backward
{
	cout << "Link::advance()\n";
	Link* p = this;
	if (p==0) return 0;
	if (0<n) {
		while (n--) {
			if (p->succ == 0) return 0;
			p = p->succ;
		}
	}
	if (n<0) {
		while (n++) {
			if (p->prev == 0) return 0;
			p = p->prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "print_all()\n";
	// rewind to beginning of list
	while (p->previous())
		p=p->previous();
	cout << "{";
	while (p) {
		cout << "addressofp: " << p << ", ";
		cout << p->value;
		if ((p=p->next())) cout << ", " ;
	}
	cout << "}\n" ;
}


int main()
{
	srcfile_info();


	Link* some_stuff = new Link("stuff-01");

	some_stuff->add(new Link("blagarg"));

	some_stuff->insert(new Link("gragalb-01"));

	some_stuff->add(new Link("stuff-02"));

	some_stuff->insert(new Link("gragalb-02"));

	print_all(some_stuff);

	some_stuff = some_stuff->find("blagarg");
	cout << some_stuff->value;

	return 0;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}
