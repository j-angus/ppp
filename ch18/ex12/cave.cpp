/**
 * @author Jason Angus
 * @file cave.cpp
 * @date 2011-10-23
 *
 * Definition of Cave class methods.
 * exercise from ch18ex12, ppp.
 * I'm going to use a linked list to create the cave. Each cave will also
 * possess attributes (boolean) to represent the presence of the various
 * characters in the game.
 */

#include "cave.h"


Cave* Cave::add(Cave* c)
// insert n after this object
{
	cout << "Link::add()\n";
	if (c==0){
		cout << "ERROR: Trying to add a NULL cave...\n";
	   	return this;
	}
	if (this==0) {
	cout << "ERROR: This is a NULL cave...\n";
	   	return n;
	}	
	if (succ) succ->prev=c;
	c->succ=succ;
	succ=c;
	c->prev=this;
	return this;
}
