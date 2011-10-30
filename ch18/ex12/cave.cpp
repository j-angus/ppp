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

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <sstream>
using std::ostringstream;

#include "cave.h"


int Cave::num_caves_=0; 

Cave::Cave() {
	cout << "Cave::Cave()\n";
	prev_=0;
	next_=0;
	// tunnels to at most three other caves
	t1_=0; 
	t2_=0; 
	t3_=0; 
	++num_caves_; // total number of caves created
	id_=num_caves_;
	bat_=false;
	pit_=false;
	wumpus_=false;
}

Cave* Cave::add(Cave* c)
// insert c after this object
{
	cout << "Cave::add()\n";
	if (c==0){
		cout << "ERROR: Trying to add a NULL cave...\n";
	   	return this;
	}
	if (this==0) {
	cout << "ERROR: This is a NULL cave...\n";
	   	return c;
	}	
	if (next_) next_->prev_=c;
	c->next_=next_;
	next_=c;
	c->prev_=this;
	return this;
}

Cave* Cave::head()
// return head of list
{
	Cave* c=this;
	while (c->prev()) {
		c=c->prev();
	}
	return c;
}

Cave* Cave::find(int id)
// find cave with matching id
{
	bool found=false;
	Cave* c=this;

	while(!found && c) {
		if (c->id()==id)
			found=true;
		else
			c=c->next();
	}
	return c;
}

/*
ostream& operator<<( ostream& os, const Cave* c )
{
	os << c->toString();
	return os;
}
*/

std::string Cave::toString() 
{
	ostringstream oss(ostringstream::out);
	oss << 
		"{\n\tprev_: " << prev_ << ", next_: " << next_ << endl <<
		"\tt1_: " << t1_ << ", t2_: " << t2_ << ", t3_: " << t3_ << endl <<
		"\tid_: " << id_ << std::endl  <<
		"\tbat_: " << (bat_ ? "true":"false") << endl <<
		"\tpit_: " << (pit_ ? "true":"false") << endl <<
		"\twumpus_: " << (wumpus_ ? "true":"false") << "\n}\n";
	return oss.str();
}

