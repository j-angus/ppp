/*
 * =============================================================================
 *
 *       Filename:  link_a.cc
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

#include "link_a.h"

Link* Link::insert(Link* n)
// insert n before this object; return n
{
	cout << "Link::insert()\n";
	// ensure n is not NULL
	if (n==0){
		cout << "ERROR: Trying to insert a NULL link...\n";
	   	return this;
	}
	if (this==0) {
	cout << "ERROR: This is a NULL link...\n";
	   	return n;
	}	
	n->succ=this;
	if (prev) prev->succ=n;
	n->prev=prev;
	prev=n;
	return n;
}

Link* Link::add(Link* n)
// insert n after this object
{
	cout << "Link::add()\n";
	if (n==0){
		cout << "ERROR: Trying to add a NULL link...\n";
	   	return this;
	}
	if (this==0) {
	cout << "ERROR: This is a NULL link...\n";
	   	return n;
	}	
	if (succ) succ->prev=n;
	n->succ=succ;
	succ=n;
	n->prev=this;
	return this;
}

Link* Link::erase()
// remove this object from list
{
	cout << "Link::erase()\n";
	if (this==0) {
		cout << "Link::erase(), nothing to remove\n";
		return 0;
	}
	if (succ) {
		cout << "Link::erase(), removing object within list\n";
		succ->prev=prev;
		if (prev) prev->succ=succ;
		else cout << "Link::erase(), object removed from top of list\n";
		return succ;
	}
	
	if (prev) {
		cout << "Link::erase(), object was at the end of the list\n";
		prev->succ=0;
		return prev;
	}
	cout << "Link::erase(), list now empty\n";
	return 0; // this was the only object in the list, list now empty
}

Link* Link::find(const string& s)
// find s in list
{
	cout << "Link::find()\n";
	
	Link* p=this;
	// using p because this is immutable
	while (p) {
		if (p->value==s) {
			cout << "Link::find(), value found\n";
			return p;
		}
		p=p->succ;
	}
/*
	// have to manipulate succ because this is immutable
	if (value==s) return this;
	while (succ) {
		if (succ->value==s) {
			cout << "Link::find(), value found\n";
		   	return succ;
		}
		succ=succ->succ;
	}
*/
	cout << "Link::find(), value not found in list\n";
	return 0; // s not found in list
}

const Link* Link::find(const string& s) const
// find s in list
{
	cout << "Link::find() const\n";
	// have to manipulate succ because this is immutable
	if (s==value) return this;
	/*
	// Keep getting errors for this function. Unable to change any values
	// because object is read-only...
	while (succ) {
		if (succ->value==s) {
			cout << "Link::find() const, value found\n";
			return succ;
		}
		succ=succ->succ;
	}
	*/
	/*
	const Link* l = this;
	while (l->succ) {
		if (l->succ->value==s) return l->succ;
		l->succ=l->succ->succ;
	}
	*/
	cout << "Link::find() const, value not found in list\n";
	return 0; // s not found in list
}

Link* Link::advance(int n)
// move n positions in list
// return 0 for "not found"
// positive n moves forward, negative backward
{
	cout << "Link::advance()\n";

	if (this==0) {
		cout << "Link::advance(), list empty\n";
		return 0;
	}
/*
   // use p because not able to change this. this is immutable
	Link* p=this;
	if (0<n) {
		while (n--) {
			if (p->succ==0) {
				cout << "Link::advance(), Hit end of list\n";
			   	return 0;
			}
			p=p->succ;
		}
	}
	if (n<0) {
		while (n++) {
			if (p->prev==0) return 0;
			p=p->prev;
		}
	}
	return p;	
*/
	// implement advance using this object
	// i reckon there will be an offset error (off by one) because
	// i can't directly manipulate this. will have to inc/dec n before
	// looping though list elements to advance the correct amount
	if (0<n) {
		--n; // because we can't directly manipulate this
		while (n--) {
			if (succ==0) {
				cout << "Link::advance(), Hit end of list\n";
				return 0;
			}
			succ=succ->succ;
		}
		return succ;
	}
	if (n<0) {
		++n; // because we can't directly manipulate this
		while (n++) {
			if (prev==0) {
				cout << "Link::advance(), Hit end of list\n";
				return 0;
			}
			prev=prev->prev;
		}
		return prev;
	}
	return this;
//*/
}
