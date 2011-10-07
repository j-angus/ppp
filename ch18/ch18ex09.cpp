/**
 * @author Jason Angus
 * @file ch18ex09.cpp
 * @date 2011-10-02
 *
 * 9. Consider the memory layout in §17.3. Write a program that tells the order
 *    in which static storage, the stack, and the free store are laid out in 
 *    memory. In which direction does the stack grow: upward toward higher 
 *    addresses or downward toward lower addresses? In an array on free store,
 *    are elements with higher indices allocated at higher or lower addresses?
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


void srcfile_info(); // display basic source file information

void show_addr(int x);
void show_addr2(int x);
// global variables
int global_1=0;
int global_2=0;

int main()
{
	srcfile_info();
	cout << "main()\n";
	cout << "&global_1: " << &global_1 << endl;
	cout << "&global_2: " << &global_2 << endl;

	show_addr(3);

	int* a1 = new int[20];
	int* a2 = new int[25];

	cout << "&a1: " << &a1 << endl;
	for (int i=0; i<20; ++i)
		cout << "&a1[" << i << "]:" << &a1[i] << endl;
	cout << "&a2: " << &a2 << endl;
	for (int i=0; i<25; ++i)
		cout << "&a2[" << i << "]:" << &a2[i] << endl;

	cout << "&show_addr(): " << (void *)show_addr << endl;
	cout << "&show_addr2(): " << (void *)show_addr2 << endl;
	return 0;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

void show_addr(int x)
{
	cout << "show-addr()\n";
	cout << "x: " << x << endl;
	static int y=5;

	cout << "y: " << y << endl;
	cout << "&x: " << &x << ", &y: " << &y << endl;

	--y;
	if (y>0)
		show_addr(y);
	return;
}

void show_addr2(int x)
{
	cout << "show-addr()\n";
	cout << "x: " << x << endl;
	static int y=5;

	cout << "y: " << y << endl;
	cout << "&x: " << &x << ", &y: " << &y << endl;

	--y;
	if (y>0)
		show_addr(y);
	return;
}
