/**
 * @file ch08ex04.cpp
 * @date 2011-06-30
 *
 * Write a function, print(), that prints a vector of ints to cout.
 * use fibonacci sequence to get an idea of the largest int valu...
 */


#include "../std_lib_facilities.h"

void print(const vector<int>& v, string vlabel); // print vector to cout
void fibonacci(int x, int y, vector<int>& v, int n); // create a fibonacci vector v of n elements


int main()
{
	const int vsize = 10; // vector size
	vector<int> my_vector; // vector to use for testing print() function
	vector<int> vfib;
	const string my_vlabel = "my_vector"; // label for the vector

	try {
		for (int i = 0; i <vsize; ++i)
			my_vector.push_back(i);
		print(my_vector, my_vlabel);
		fibonacci(1, 2, my_vector, vsize);
		print(my_vector, "fibonacci numbers");
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
