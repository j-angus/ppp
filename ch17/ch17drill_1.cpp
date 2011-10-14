/**
 * @author Jason Angus
 * @file ch17drill_1.cpp
 * @date 2011-08-15
 *
 * drill 1, page 607
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;
using std::stringstream;

#include <vector>
using std::vector;


/* Write a function print_array10(ostream& os, int* a)
 * that prints out the values of a (assumed to have ten elements) to os.
 */
void
print_array10(ostream& os, int* a)
{
	for (int i=0; i<10; ++i)
		os << "a[" << i << "] = " << a[i] << endl;
}

/* Write a function print_array(ostream& os, int* a, int n) that prints out
 * the values of a (assumed to have n elements) to os.
 */
void
print_array(ostream& os, int* a, int n)
{
	for (int i=0; i<n; ++i)
		os << "a[" << i << "] = " << a[i] << endl;
}

// initialise array a of n elements starting with value v
void
init_array(int *a, int n, int v)
{
	for (int i=0; i<n; ++i, ++v)
		a[i]=v;
}

// initialise vector of ints v starting with value val
void
init_vector(vector<int>& v,int val)
{
	for (size_t i=0; i<v.size(); ++i, ++val)
		v[i]=val;
}

void
print_vector(ostream& os, vector<int>& v)
{
	for (size_t i=0; i<v.size(); ++i)
		os << "v[" << i << "] = " << v[i] << endl;
}

int main()
{
	cout << "ch17drill_1.cpp\n\n";

	int size=10;
	// Allocate an array of ten ints on the free store using new.
	int* ip = new int[size];

	// display contents of ip
	for (int i=0; i<size; ++i) {
		cout << "ip[" << i << "] = " << ip[i] << endl;
		cout << "ip+" << i << " = " << ip+i << endl;
	}

	// display value of ip... (address of base of array...)
	cout << "ip = " << ip << endl;
	for (int i=0; i<size; ++i)
		ip[i]=i;

	print_array10(cout, ip);

	// deallocate array
	delete[] ip;
/*
	// error, ip deallocated...
	for (int i=0; i<size; ++i)
		ip[i]=i+10;
	print_array10(cout, ip);
	//print_array(cout, ip, 20); // ip deallocated and only 10 long initially
*/

	// deallocate array - error, second deallocation...
	// delete[] ip;
	size=20;
	int* ip2 = new int[size];
	init_array(ip2, size, 100);
	print_array(cout, ip2, size);
	// display value of ip2... (address of base of array...)
	cout << "ip2 = " << ip2 << endl;
	delete[] ip2;
	// this should be bad code:
	//print_array(cout, ip, size); // ip deallocated and only 10 long initially

	vector<int> vec(10);
	init_vector(vec, 0);
	print_vector(cout, vec);

	vector<int> vec2(20);
	init_vector(vec2, 100);
	print_vector(cout, vec2);

return 0;
}