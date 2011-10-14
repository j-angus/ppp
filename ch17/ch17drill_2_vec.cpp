/**
 * @author Jason Angus
 * @file ch17drill_2_vec.cpp
 * @date 2011-08-22
 *
 * drill 1, page 608
 */

/* 1. Allocate an int, initialize it to 7, and assign its address to a
 *    variable p1.
 * 2. Print out the value of p1 and of the int it points to.
 * 3. Allocate an array of seven ints; initialize it to 1,2,4,8, etc.; and
 *    assign its address to a variable p2.
 * 4. Print out the value of p2 and of the array it points to.
 * 5. Declare an int* called p3 and intialize it with p2.
 * 6. Assign p1 to p2.
 * 7. Assign p3 to p2.
 * 8. Print out the values of p1 and p2 and of what they point to.
 * 9. Deallocate all the memory you allocated from the free store.
 * 10. Allocate an array of ten ints; initialize it to 1, 2,4, 8, etc.; and
 *     assign its address to a variable p1.
 * 11. Allocate an array of ten ints, and assign its address to a variable p2.
 * 12. Copy the values from the array pointed to by p1 into the array pointed to
 *     by p2.
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

#include <cstdio>
using std::printf;


// prints a vector of ints
void
print_vector(ostream& os, vector<int>& v)
{
	for (size_t i=0; i<v.size(); ++i)
		os << "v[" << i << "] = " << v[i] << endl;
}


int main()
{
	cout << "ch17drill_2_vec.cpp\n\n";

	vector<int> v1(10);
	for (size_t i=0; i<v1.size(); ++i)
		v1[i]=(i+1)*2;
	vector<int>* vp1 = &v1;
	cout << "vector v1:\n";
	print_vector(cout, v1);

	vector<int> v2(10);
	vector<int>* vp2 = &v2;
	cout << "vector v2:\n";
	print_vector(cout, v2);

	cout << "Copy and display values from v1 to v2\n";
	for (int i=0; i<10; ++i) {
		vp2->at(i)=vp1->at(i);
		printf("vp1[%d]=%d\n", i, vp1->at(i));
	}
	cout << "vector pointer vp2:\n";
	print_vector(cout, *vp2);

return 0;
}