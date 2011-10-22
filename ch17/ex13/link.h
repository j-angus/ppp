/*
 * =============================================================================
 *
 *       Filename:  link.h
 *
 *    Description:  Declaration of Link class
 *
 *        Version:  1.0
 *        Created:  13/10/11 08:29:45
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jason Angus
 *
 * =============================================================================
 */

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#ifndef LINK_H
#define LINK_H

struct God {
	God (const string& n="", const string& m="",
		const string& v="", const string& w="")
		: name(n), mythology(m), vehicle(v), weapon(w) {}
	string name;
	string mythology;
	string vehicle;
	string weapon;
};

class Link {
public:
	Link(const string& n="", const string& m="", const string& v="",
			const string& w="", Link* p=0, Link* s=0)
		: prev(p), succ(s) { 
			cout << "Link::Link()\n";
			cout << "address of this: "	<< this << endl;
			god=new God();
			god->name=n;
			god->mythology=m;
			god->vehicle=v;
			god->weapon=w;
	}

	God* god;

	Link* insert(Link* n);			// insert n before this object
	Link* add(Link* n);				// insert n after this object
	Link* add_ordered(Link* n);		// insert n after this object
									// in lexicographical order within list
	Link* erase();					// remove this object from list
	Link* find(const string& s); 	// find s in list
	const Link* find(const string& s) const; // find s in list
	Link* head(); 					// returns the head of the list
	Link* advance(int n);			// move n positions in list

	Link* next() const {return succ;}
	Link* previous() const {return prev;}


private:
	Link* prev;
	Link* succ;
};
#endif // LINK_H
