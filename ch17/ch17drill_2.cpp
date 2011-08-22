/**
 * @author Jason Angus
 * @file ch17drill_2.cpp
 * @date 2011-08-20
 *
 * drill 1, page 608
 */

/* 1. Allocate an int , initialize it to 7, and assign its address to a
 * variable p1.
 * 2. Print out the value of p1 and of the int it points to.
 * 3. Allocate an array of seven ints; initialize it to 1,2,4,8, etc.; and
 * assign its address to a variable p2.
 * 4. Print out the value o f p2 and of the array it points to.
 * 5. Declare an int* called p3 and intialize it with p2.
 * 6. Assign pl to p2.
 * 7. Assign p3 to p2.
 * 8. Print out the values of p1 and p2 and of what they point 10.
 * 9. Deallocate all the memory you allocated from the free store.
 * 10. Allocate an array of ten ints; initialize it to 1, 2,4, 8, etc.; and
 * assign its address to a variable p1.
 * 11. Allocate an array of ten ints, and assign its address to a variable p2.
 * 12. Copy the values from the array pointed to by p1 into the array pointed to
 * by p2.
 * 13. Repeat 10-12 using a vector rather than an array.
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

int main()
{
	cout << "ch17drill_2.cpp\n\n";

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