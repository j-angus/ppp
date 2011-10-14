// link.cpp

#include "link.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Link* Link::insert(Link* n)	// insert n before this object; return n
{
	if (n==0) return this;	// nothing to insert
	if (this==0) return n;	// nothing to insert into
	n->succ = this;			// this object comes after n
	if (prev) prev->succ = n;
	n->prev = prev;			// the object's predecessor
							// becomes n's predecessor
	prev = n;				// n becomes this objects's predecessor
	return n;
}

Link* Link::add(Link* n) // insert n after p; return n
{
	// much like insert()
	return n;
}

Link* Link::erase() // remove *p from list; return p's successor
{
	if (this==0) return 0;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;
}

Link* Link::find(const string& s) // find s in list;
								   // return 0 for "not found"
{
	Link* p = this;
	while (this) {
		if (value == s) return this;
		p = succ;
	}
	return 0;
}

Link* Link::advance(int n) const	// move n positions in list
									// return 0 for "not found"
	// positive n moves forward, negative backward
{
	if (this==0) return 0;
	if (0<n) {
		while (n--) {
			if (succ == 0) return 0;
			this = succ;
		}
	}
	if (n<0) {
		while (n++) {
			if (prev == 0) return 0;
			this = prev;
		}
	}
	return this;
}

void print_all(Link *p)
{
	cout << "{";
	while (p) {
		cout << p->value;
		if ((p=p->next())) cout << "," ;
	}
	cout << "}";
}
