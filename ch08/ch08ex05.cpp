/**
 * @file ch08ex05.cpp
 * @date 2011-06-30
 *
 * Write two functions that reverse the order of elements in a vector<int>.
 * For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function
 * should produce a new vector with the reversed sequence, leaving its orig-
 * inal vector unchanged. The other reverse function should reverse the el-
 * ements of its vector without using any other vectors (hint : swap).
 */


#include "../std_lib_facilities.h"

void print(const vector<int>& v, string vlabel); // print vector to cout
void fibonacci(int x, int y, vector<int>& v, int n); // create a fibonacci vector v of n elements
vector<int> vrev_1(const vector<int>& v); // reverse elements of a vector, return by copy
void vrev_2(vector<int>& v); // reverse elements of a vector, return by reference

int main()
{
	const int vsize = 10; // vector size
	vector<int> my_vector; // vector to use for testing print() function
	vector<int> vfib;
	vector<int> rv;
	const string my_vlabel = "my_vector"; // label for the vector

	try {
		for (int i = 0; i <vsize; ++i)
			my_vector.push_back(i);
		print(my_vector, my_vlabel);
		fibonacci(1, 2, my_vector, vsize);
		print(my_vector, "fibonacci numbers");
		rv.resize(my_vector.size());
		rv=vrev_1(my_vector);
		print(rv, "fib reversed by copy");
		vrev_2(rv);
		print(rv, "rv reversed by reference");
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;

		return 1;
}
	return 0;
}

/**
 * print()
 * print the contents of a vector to cout
 */
void print(const vector<int>& v, const string vlabel)
{
	cout << vlabel << endl;
	for (int i=0; i<v.size(); ++i)
		cout << v[i] << endl;
	return;
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.clear();
	//v.resize(n, 0);
	v.push_back(x);
	v.push_back(y);
	//v[0]=x;
	//v[1]=y;
	for (int i=2; v[i-1]>0; ++i) {
		v.push_back(v[i-1]+v[i-2]);
		cout << "v[" << i << "]: " << v[i] << endl;
	}
		//v[i]=v[i-1]+v[i-2];
	return;
}

vector<int> vrev_1(const vector<int>& v) // reverse elements of a vector, return by copy
{
	vector<int> vrev;

	for (int i=v.size()-1; i>=0; --i) {
		vrev.push_back(v[i]);
	}

	return vrev;
}

void vrev_2(vector<int>& v) // reverse elements of a vector, return by reference
{
	for (int i=0, j=v.size()-1; i<j; ++i, --j) {
		swap(v[i], v[j]);
	}
	return;
}
