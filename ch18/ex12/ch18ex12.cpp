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
ostream& operator<<(ostream& os, const Cave& aCave);

int main()
{
	srcfile_info();
	cout << "main()\n";

	Cave myCave;

	cout << myCave;

	Cave myOtherCave;

	cout << myOtherCave;
}

// overload << operator to print all Cave attributes
ostream& operator<<(ostream& os, const Cave& aCave)
{
	os << "Cave Object:\n{\n";
	os << "prev_: " << aCave.prev_ << endl;
	os << "next_: " << aCave.next_ << endl;
	os << "t1_: " << aCave.t1_ << endl;
	os << "t2_: " << aCave.t2_ << endl;
	os << "t3_: " << aCave.t3_ << endl; 
	os << "num_caves_: " << aCave.num_caves_ << endl;
	os << "bat_: " << (aCave.bat_ ? "true" : "false") << endl;
	os << "pit_: " << (aCave.pit_ ? "true" : "false") << endl;
	os << "wumpus_: " << (aCave.wumpus_ ? "true" : "false") << endl;
	os << "id_: " << aCave.id_ << endl;
	os << "}\n";
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
