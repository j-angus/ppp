/**
 * @author Jason Angus
 * @file cave.h
 * @date 2011-10-23
 *
 * Declaration of a Class to represent a cave for the hunt-the-wumpus
 * exercise from ch18ex12, ppp.
 * I'm going to use a linked list to create the cave. Each cave will also
 * possess attributes (boolean) to represent the presence of the various
 * characters in the game.
 */

#ifndef CAVE_H
#define CAVE_H

#include <iostream>
using std::ostream;

class Cave {
public:
	Cave();
	//~Cave();

	Cave* add(Cave* c);
	Cave* insert(Cave* c);
	Cave* head(); // return head of list
	Cave* find(int cave_id); // search by cave id_
	Cave* prev() const { return prev_; }
	Cave* next() const { return next_; }

	bool has_bat() const { return bat_; }
	bool has_pit() const { return pit_; }
	bool has_wump() const { return wumpus_; }
	int id() const { return id_; }

	void status(); // display status of cave atttributes
	// overload << operator to print all Cave attributes
	friend ostream& operator<<(ostream& os, const Cave& aCave);
private:
	Cave* prev_;
	Cave* next_;
	// tunnels to at most three other caves
	Cave* t1_; 
	Cave* t2_; 
	Cave* t3_; 
	static int num_caves_; // total number of caves created
	int id_; // The number of the cave. Allows referencing caves.
	bool bat_;
	bool pit_;
	bool wumpus_;

}; // Cave
#endif // CAVE_H

