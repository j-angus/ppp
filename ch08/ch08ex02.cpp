/**
 * @file ch08ex02.cpp
 * @date 2011-06-29
 *
 * Write a function, print(), that prints a vector of ints to cout.
 */


#include "../std_lib_facilities.h"

void print(const vector<int>& v, string vlabel); // print vector to cout
 fibonacci(int x, int y, vector<int> v, int n)


int main()
{
	const int vsize = 10; // vector size
	vector<int> my_vector; // vector to use for testing print() function
	string my_vlabel = "my_vector"; // label for the vector

	for (int i = 0; i <vsize; ++i)
		my_vector.push_back(i);

	try {
		print(my_vector, my_vlabel);
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
void print(const vector<int>& v, string vlabel)
{
	cout << vlabel << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	return;
}
