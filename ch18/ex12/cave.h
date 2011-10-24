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

class Cave {
public:
	Cave() {
		bat=false;
		pit=false;
		wumpus=false;
		id=0;
		++id;
	}

	Cave* add(Cave* c);
	Cave* insert(Cave* c);
	Cave* prev() const { return pred; }
	Cave* next() const { return succ; }
	Cave* head(); // return head of list

	bool has_bat() const { return bat; }
	bool has_pit() const { return pit; }
	bool has_wump() const { return wumpus; }
	int id() const { return cave_id; }

	void status(); // display status of cave atttributes

private:
	Cave* pred;
	Cave* succ;
	// tunnels to at most three other caves
	Cave* t1; 
	Cave* t2; 
	Cave* t3; 
	int cave_id; // The number of the cave. Allows referencing caves.
	static int num_caves; // total number of caves created
	bool bat;
	bool pit;
	bool wumpus;

} // Cave
#endif // CAVE_H

