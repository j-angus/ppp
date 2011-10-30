/*
 * @author Jason Angus
 * @file ch18ex12.cpp
 * @date 2011-10-23
 *
 * Write "hunt the wumpus" from ch18 ex12, page 644
 *
 */

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <cstdlib>
#include "cave.h"

void srcfile_info(); // display basic source file information

inline int randint(int max) { return rand()%max; }
inline int randint(int min, int max) { return randint(max-min)+min; }

// overload << operator to print Cave attributes
ostream& operator<<(ostream& os, Cave* c);

void print_caves(Cave* c);

void init_cave(Cave* c, int bats, int pits);

int main()
{
	srcfile_info();
	cout << "main()\n";
	const int cave_size = 12; // Total number of caves to create
	const int num_bats = cave_size/4;
	const int num_pits = cave_size/4;

	// Initialise cave list and cave data before getting into gameplay
	// Create a list of caves
	Cave* myCave = new Cave();
	// cout << myCave;
	print_caves(myCave);
	
	while (myCave->num_caves()<cave_size) {
		myCave->add(new Cave());
	}
	print_caves(myCave);

	// Ok, so here need to setup links between caves, bats, pits and the wumpus
	// This is cave initialisation after creating the cave list
	init_cave(myCave, num_bats, num_pits);
	print_caves(myCave);
}

void init_cave(Cave* c, int bats, int pits)
// initialise cave list attributes
{
	cout << "init_cave()\n";
	if (!c) {
		cout << "Error: no cave to initialise...\nx:";
	}
	if (bats>c->num_caves()) {
		cout << "error, too many bats!, only one per cave allowed.\n" <<
			"bats: " << bats << ", num_caves: " << c->num_caves() << endl;
		return;
	}
	if (bats<0) {
		cout << "Error: can't have negative number of bats, sorry...\n";
		return;
	}
	if (pits>c->num_caves()) {
		cout << "error, too many pits!, only one per cave allowed.\n" <<
			"pits: " << pits << ", num_caves: " << c->num_caves() << endl;
		return;
	}
	if (pits<0) {
		cout << "Error: can't have negative number of pits, sorry...\n";
		return;
	}
	// set the wump
	int cave_id=randint(1,c->num_caves());
	c=c->head();
	c=c->find(cave_id);
	c->set_wump(true);
	c=c->head();
	// set bats
	while (bats) {
		cave_id=randint(1,c->num_caves());
		c=c->find(cave_id);
		if (!c->bat()) {
			c->set_bat(true);
			--bats;
		}
		c=c->head();
	}
	// set pits
	while (pits) {
		cave_id=randint(1,c->num_caves());
		c=c->find(cave_id);
		if (!c->pit()) {
			c->set_pit(true);
			--pits;
		}
		c=c->head();
	}
}

void print_caves(Cave* c)
{
	cout << "print_caves()\n";
	while (c) {
		cout << "Cave Object: " << &c << endl << c << endl;
		c=c->next();
	}
	return;
}

// overload << operator to print Cave attributes
std::ostream& operator<<(std::ostream& os, Cave* c)
{
	os << c->toString();
	return os;
}

void srcfile_info()
{
	cout << "srcfile_info()\n";
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

