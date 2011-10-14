/**
 * @author Jason Angus
 * @file ch18drill02.cpp
 * @date 2011-09-10
 * 
 * Standard library vector drill:
 *
 * 1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16. etc.
 * 2. Define a function f() taking a vector<int> argument.
 * 3. In f():
 *    a. Define a local vector<int> lv with the same number of elements as the
 *       argument vector.
 *    b. Copy the values from gv into lv.
 *    c. Print out lhe elements of lv.
 *    d. Define a local veclor<int> 1v2; initialize it to be a copy of the 
 *       argument array.
 *    e. Print out the elements of lv2.
 * 4. In main() :
 *    a. Call f() with gv as its argument.
 *    b. Define a vector<int> vv, and initialize it with the first ten factorial 
 *       values (1, 2*1, 3*2*1 , 4*3*2*1, etc.).
 *    c. Call f() with vv as its argument.
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

void srcfile_info(); // display basic source file information

void f(const vector<int>& vip);

vector<int> gv(10);

int main()
{
	srcfile_info();
	gv[0]=1;
	for (int i=1; i<gv.size(); ++i)
		gv[i]=gv[i-1]*2;

	vector<int> vv(10);
	for (int i=0; i<vv.size(); ++i)
		vv[i]=i*4;

	f(gv);
	f(vv);
	return 0;
}


void f(const vector<int>& vip)
{
	vector<int> lv(vip.size());
	lv=gv;

	cout << "lv:\n";
	for (int i=0; i<lv.size(); ++i)
		cout << lv[i] << ((i<(lv.size()-1))? ", " : "\n");

	vector<int> lv2(vip);
	
	cout << "lv2:\n";
	for (int i=0; i<lv2.size(); ++i)
		cout << lv2[i] << ((i<(lv2.size()-1))? ", " : "\n");
	
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

