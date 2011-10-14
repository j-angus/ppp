/**
 * @author Jason Angus
 * @file ch18tt-page265.cpp
 * @date 2011-09-09
 * 
 * Try this from PPP page 625.
 * Try out a vector implementation.
 * See section 17.6, page 590
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

class my_vector 
{
	int sz;		// number of elements
	int* elem;	// data storage
	
public:
	my_vector(int s): sz(s), elem(new int[s]){}	// constructor
	~my_vector(){ delete[] elem; }
	
	int size() const { return sz; }	// the current size
	
	int get(int n){ return elem[n]; }	// access: read
	void set(int n, int v){ elem[n]=v; }	// access: write
	
	int operator[](int n){return elem[n]; }	// return element
	
};

int main()
{
	srcfile_info();
	
	my_vector mv(10);
	int x=mv[2]; // fine
	mv[3]=x; // error: v[3] not an lvalue
	cout << "mv[3]: " << mv[3] << endl;	
	return 0;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

