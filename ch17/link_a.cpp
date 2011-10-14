/*
 * =============================================================================
 *
 *       Filename:  link_a.cpp
 *
 *    Description:  Definition of Link class methods
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

#include <iostream>
using std::cin;
using std::cout;

#include "link_a.hpp"


Link* Link::insert(Link* n)
// insert n before this object
{
	cout << "Link::insert()\n";
	n->succ=this;
	prev=n;
	return n;
}

Link* Link::add(Link* n)
// insert n after this object
{
	cout << "Link::add()\n";
	n->succ=succ;
	n->prev=this;
	succ=n;
	return this;
}

Link* Link::erase()
// remove this object from list
{
	cout << "Link::erase()\n";
	if (prev) {
		prev->succ=succ;
		succ->prev=prev;
		return prev;
	}
	else {
		succ->prev=0;
		return succ;
	}
}

Link* Link::find(const string& s)
// find s in list
{
	cout << "Link::find()\n";
	if (s==value) return this;
	while (succ) {
		if (s==succ->value) return succ;
		succ=succ->succ;
	}
	return 0; // s not found in list
}

const Link* Link::find(const string& s) const
// find s in list
{
	cout << "Link::find() const\n";
	if (s==value) return this;
	/*
	const Link* l = this;
	while (l->succ) {
		if (l->succ->value==s) return l->succ;
		l->succ=l->succ->succ;
	}
	*/
	return 0; // s not found in list
}

Link* Link::advance(int n)
// move n positions in list
{
	cout << "Link::advance()\n";
	if (0<n) {
		if (succ)
			succ=succ->succ;
		for (int i=1; i<n; ++i) {
			if (succ)
				succ=succ->succ;
			else {
				cout << "ERROR: Link::advance(), range error\n";
				return 0;
			}
		}
		return this;
	}
	else if (n<0) {
		if (prev)
			prev=prev->prev;
		for (int i=-1; i>n; --i) {
			if (prev) {
				succ=prev;
				prev=prev->prev;
			}
			else {
				cout << "ERROR: Link::advance(), range error\n";
				return 0;
			}
		}
		return this;
	}

	return this;
}

