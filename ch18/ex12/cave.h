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
	Cave* t1() const { return t1_; }
	Cave* t2() const { return t2_; }
	Cave* t3() const { return t3_; }
	
	std::string toString();
	ostream& Print(ostream& os);

	void set_bat(bool state) { bat_=state; }
	bool bat() const { return bat_; }
	void set_pit(bool state) { pit_=state; }
	bool pit() const { return pit_; }
	void set_wump(bool state) { wumpus_=state; }
	bool wump() const { return wumpus_; }
	
	int num_caves() const { return num_caves_; }
	int id() const { return id_; }

	void status(); // display status of cave atttributes
	// overload << operator to print all Cave attributes
	//friend ostream& operator<<(ostream& os, Cave* aCave);
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
