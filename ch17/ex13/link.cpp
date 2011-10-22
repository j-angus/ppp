/*
 * =============================================================================
 *
 *       Filename:  link.cpp
 *
 *    Description:  Definition of Link class methods
 *
 *        Version:  1.0
 *        Created:  21/10/2011 08:29:45
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

#include "link.h"

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

Link* Link::add_ordered(Link* n)
// insert n in correct lexicographical order within the list
{
	cout << "Link::add_ordered()\n";
	if (n==0){
		cout << "ERROR: Trying to add a NULL link...\n";
	   	return this;
	}
	if (this==0) {
	cout << "ERROR: This is a NULL link...\n";
	   	return n;
	}	
	// traverse list here, lookng for lexicograhical location for 
	// n->god->name to fit in...
	// find the head of the list...prev == 0
	Link* p = this;
	while (p->previous())
		p=p->previous();
	// compare god->name between this and n...
	//if this->god->name < n->god->name move to the next Link
	// if this->god->name > n->god->name move back to prev Link
	
	if ((n->god->name < p->god->name)) {
		cout << n->god->name << " < " << p->god->name << endl;
		p->insert(n);
		
		return head();
	}
	
	cout << "comparing: " 
			<< n->god->name << " and " << p->god->name << endl;
	while (p->next()) {
		if ((n->god->name > p->god->name) &&
			(n->god->name > p->next()->god->name))
			p=p->next();
		else
			break;
	}

	p->add(n);
	return head();
	/*
	if (p->succ) p->succ->prev=n;
	n->succ=p->succ;
	p->succ=n;
	n->prev=p;
	return n;
	* */
}

// returns the head of the list
Link* Link::head() {
	cout << "Link::head()\n";
	Link* p=this;
	while (p->previous())
		p=p->previous();
	return p;
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
		cout << "this: " << this << ", this->god->name: " << this->god->name 
			<< ", this->prev: " << this->prev 
			<< ", this->succ: " << this->succ << endl;
		cout << "p: " << p << ", p->god->name: " << p->god->name 
			<< ", p->prev: " << p->prev 
			<< ", p->succ: " << p->succ << endl;
		if (p->god->name==s) {
			cout << "Link::find(), value found\n";
			return p;
		}
		p=p->succ;
	}
	cout << "Link::find(), value not found in list\n";
	return 0; // s not found in list
}

const Link* Link::find(const string& s) const
// find s in list
{
	cout << "Link::find() const\n";
	// have to manipulate succ because this is immutable
	if (s==god->name) return this;
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
}
