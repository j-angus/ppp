/**
 * @author Jason Angus
 * @file ch17drill_2.cpp
 * @date 2011-08-20
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


/* prints out the values of a (assumed to have n elements) to os.
 */
void
print_array(ostream& os, int* a, int n)
{
	for (int i=0; i<n; ++i)
		os << "a[" << i << "] = " << a[i] << endl;
}

// prints a vector of ints
void
print_vector(ostream& os, vector<int>& v)
{
	for (size_t i=0; i<v.size(); ++i)
		os << "v[" << i << "] = " << v[i] << endl;
}


int main()
{
	cout << "ch17drill_2.cpp\n\n";

	int my_int=7;
	int* p1 = &my_int;

	cout << "p1=" << p1 << ", *p1=" << *p1 << endl;

	int* ia = new int[7];
	//int ia[7];
	for (int i=0; i<7; ++i)
		ia[i]=i+1;
	int* p2=ia;
	cout << "p2=" << p2 << ", *p2=" << *p2 << endl;
	cout << "ia=" << ia << ", *ia=" << *ia << endl;

	int* p3 = p2;
	p2=p1;
	p1=p3;
	cout << "p1=" << p1 << ", *p1=" << *p1 << endl;
	cout << "p2=" << p2 << ", *p2=" << *p2 << endl;

	delete[] ia;
	cout << "DEBUG: deleted ia[]\n";

	int* iaa = new int[10];
	for (int i=0; i<10; ++i)
		iaa[i]=(i+1)*2;
	p1 = iaa;

	int* ib = new int(10);
	p2=ib;

	// print initial values of arrays:
	cout << "iaa:\n";
	print_array(cout, iaa, 10);
	cout << "ib:\n";
	print_array(cout, ib, 10);

	// copy iaa to ib
	for (int i=0; i<10; ++i)
		*(p2+i)=*(p1+i);
	cout << "ib after copying:\n";
	print_array(cout, ib, 10);

	delete[] iaa;
	cout << "DEBUG: deleted iaa[]\n";

	vector<int> v1(10);
	for (size_t i=0; i<v1.size(); ++i)
		v1[i]=(i+1)*2;
	vector<int>* vp1 = &v1;
	cout << "Vector v1:\n";
	print_vector(cout, v1);

	cout << "about to declare v2\n";
	vector<int> v2(10);
	cout << "declared v2\n";
	for (size_t i=0; i<v2.size(); ++i)
		v2[i]=i;
	vector<int>* vp2 = &v2;
	cout << "Vector v2:\n";
	print_vector(cout, v2);

	cout << "Copy and display values from v1 to v2\n";
	for (int i=0; i<10; ++i) {
		vp2[i]=vp1[i];
		//cout << "vp2[" <<i<< "]=" << vp2[i] << endl;
		//cout << *vp2+i;
	}

	print_vector(cout, *vp2);

return 0;
}