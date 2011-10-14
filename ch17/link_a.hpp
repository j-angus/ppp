/*
 * =============================================================================
 *
 *       Filename:  link_a.hpp
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

#ifndef LINK_A_HPP
#define LINK_A_HPP

class Link {
public:
	string value;
	Link(const string& v, Link* p=0, Link* s=0)
		:value(v), prev(p), succ(s) {}

	Link* insert(Link* n);		// insert n before this object
	Link* add(Link* n);		// insert n after this object
	Link* erase();			// remove this object from list
	Link* find(const string& s); 	// find s in list
	const Link* find(const string& s) const; // find s in list

	Link* advance(int n);		// move n positions in list

	Link* next() const {return succ;}
	Link* previous() const {return prev;}

private:

	Link* prev;
	Link* succ;
};
#endif // LINK_A_HPP
