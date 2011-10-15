/*
 * =============================================================================
 *
 *       Filename:  link_a.h
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

// attempting to use make's implicit rules for compilation
// the implicit rule for link_a.o is proving tricky because of the added
// header file. Bummer.
// trying the vpath direction to pickup this header file as a dependency
// and still use implicit default rules
//
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#ifndef LINK_A_H
#define LINK_A_H

class Link {
public:
	string value;
	Link(const string& v, Link* p=0, Link* s=0)
		:value(v), prev(p), succ(s) { 
			cout << "Link::Link()\n"; cout << "address of this: " 
				<< this << endl; }


	Link* insert(Link* n);			// insert n before this object
	Link* add(Link* n);				// insert n after this object
	Link* erase();					// remove this object from list
	Link* find(const string& s); 	// find s in list
	const Link* find(const string& s) const; // find s in list

	Link* advance(int n);			// move n positions in list

	Link* next() const {return succ;}
	Link* previous() const {return prev;}

private:

	Link* prev;
	Link* succ;
};
#endif // LINK_A_H
