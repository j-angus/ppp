/**
 * @author Jason Angus
 * @file ch18drill01.cpp
 * @date 2011-09-09
 * 
 * Array exercises:
 *
 * 1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
 * 2. Define a function f() taking an int array argument and an int argument
 *    indicating the number of elements in the array.
 * 3. In f():
 *    a. Define a local int array la of ten ints.
 *    b. Copy the values from ga into la .
 *    c. Print out the elements of la.
 *    d. Define a pointer p to int and initialize it with an array allocated on the
 *       free store with the same number of elements as the argument array.
 *    e. Copy the values from the argument array into the free-store array.
 *    f. Print out the elements of the free-store array.
 *    g. Deallocate the free-store array.
 * 4. In main ():
 *    a. Call f() with ga as its argument.
 *    b. Define an array aa with ten elements, and initialize it with ule fi rst ten
 *       factorial values (1, 2·1, 3· 2·1, 4*3·2·1, etc.).
 *    c. Call fO with aa as its argument.

 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

//#include <vector>
//using std::vector;

void srcfile_info(); // display basic source file information

void f(const int ia[], int sz);

int ga[] = {1,2,4,8,16,32,64,128,256,512};
int gasz = 10;

int main()
{
	srcfile_info();
	int aa[] = {2,4,6,8,10,12,14,16,18,20,22};
	int aasz = 11;	
	f(ga, gasz);
	f(aa, aasz);
	return 0;
}


void f(const int ia[], int sz)
{
	int la[10];
	cout << "la[]:\n";
	for (int i=0; i<gasz; ++i) {
		la[i]=ga[i];
		cout << la[i] << ((i<(gasz-1))? ", " : "\n");
	}
	int* p = new int[sz];
	cout << "p[]:\n";
	for (int i=0; i<sz; ++i) {
		p[i]=ia[i];
		cout << p[i] << ((i<(sz-1))? ", " : "\n");
	}
	delete[] p;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

