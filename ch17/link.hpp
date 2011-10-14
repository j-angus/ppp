// link.hpp

#include <string>
using std::string;

#ifndef LINK_HPP
#define LINK_HPP

class Link {
public:
	string value;
	Link(const string& v, Link* p = 0, Link* s = 0)
		: value(v), prev(p), succ(s) {}
	Link* insert(Link* n);			// Insert n before this object
	Link* add(Link* n);				// Insert n after this object
	Link* erase();					// remove this object from list
	Link* find(const string& s);	// find s in list
	const Link* find(const string& s) const; // find s in list

	Link* advance(int n) const;		// move n positions in list

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private :
	Link* prev;
	Link* succ;
};

#endif
