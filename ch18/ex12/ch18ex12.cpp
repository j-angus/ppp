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

#include "cave.h"

void srcfile_info(); // display basic source file information

// overload << operator to print all Cave attributes
//ostream& operator<<(ostream& os, Cave* aCave);
void print_caves(Cave* c);

void init_cave(Cave* c, int bats, int pits);

int main()
{
	srcfile_info();
	cout << "main()\n";
	const int cave_size = 8; // Total number of caves to create
	const int num_bats = cave_size/2;
	const int num_pits = cave_size/2;

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
	// init_cave(myCave, num_bats, num_pits);
}

void init_cave(Cave* c, int bats, int pits)
// initialise a cave list
{
	// check that bats is less than c->cave_number
	// check that pits is less than c->cave_number
	// wump must be set if c->next() == zero 
	while (c) {
		// randomly set bat to true, decrement bats if bat is set
		// randomly set pit to true, decrement pits if pit is set
		// randomly set wump to true, set a wump_set flag to true
		// randomly set three tunnel links to other caves for each cave
		c=c->next();
	}

}

void print_caves(Cave* c)
{
	while (c) {
		cout << "Cave Object: " << c << endl;
		cout << "{\n";
		cout << "prev_: " << c->prev() << endl;
		cout << "next_: " << c->next() << endl;
		cout << "t1_: " << c->t1() << endl;
		cout << "t2_: " << c->t2() << endl;
		cout << "t3_: " << c->t3() << endl; 
		cout << "num_caves_: " << c->num_caves() << endl;
		cout << "bat_: " << (c->bat() ? "true" : "false") << endl;
		cout << "pit_: " << (c->pit() ? "true" : "false") << endl;
		cout << "wump_: " << (c->wump() ? "true" : "false") << endl;
		cout << "id_: " << c->id() << endl;
		cout << "}\n";
		c=c->next();
	}
	return;
}

// overload << operator to print all Cave attributes
/*
ostream& operator<<(ostream& os, Cave* aCave)
{
	os << "Cave Object:\n{\n";
	os << "prev_: " << aCave->prev() << endl;
	os << "next_: " << aCave->next() << endl;
	os << "t1_: " << aCave->t1() << endl;
	os << "t2_: " << aCave->t2() << endl;
	os << "t3_: " << aCave->t3() << endl; 
	os << "num_caves_: " << aCave->num_caves() << endl;
	os << "bat_: " << (aCave->bat() ? "true" : "false") << endl;
	os << "pit_: " << (aCave->pit() ? "true" : "false") << endl;
	os << "wump_: " << (aCave->wump() ? "true" : "false") << endl;
	os << "id_: " << aCave->id() << endl;
	os << "}\n";
	return os;
}
*/

void srcfile_info()
{
	cout << "srcfile_info()\n";
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}
