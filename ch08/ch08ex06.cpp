/**
 * @file ch08ex06.cpp
 * @date 2011-07-02
 *
 * Write two functions that reverse the order of elements in a vector<int>.
 * For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function
 * should produce a new vector with the reversed sequence, leaving its orig-
 * inal vector unchanged. The other reverse function should reverse the el-
 * ements of its vector without using any other vectors (hint : swap).
 */


#include "../std_lib_facilities.h"

void print(const vector<string>& v, string label); // print vector of strings to cout
vector<string> vrev_1(const vector<string>& v); // reverse elements of a vector, return by copy
void vrev_2(vector<string>& v); // reverse elements of a vector, return by reference

int main()
{
	const int vsize = 10; // vector size
	vector<string> vstr_1; // vector of strings
	vector<string> vstr_2; // vector of strings
	const string label1 = "vstr_1"; // label for vector
	const string label2 = "vstr_2"; // label for vector

	try {
		for (int i = 0; i <vsize; ++i)
			vstr_1.push_back("string-" + to_string(i));
		print(vstr_1, label1);

		vstr_2.resize(vstr_1.size());
		vstr_2=vrev_1(vstr_1);
		print(vstr_2, label2 +" reversed by copy");
		vrev_2(vstr_2);
		print(vstr_2, label2 + " reversed by reference");
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
void print(const vector<string>& v, const string vlabel)
{
	cout << vlabel << endl;
	for (int i=0; i<v.size(); ++i)
		cout << v[i] << endl;
	return;
}


vector<string> vrev_1(const vector<string>& v) // reverse elements of a vector, return by copy
{
	vector<string> vrev;

	for (int i=v.size()-1; i>=0; --i) {
		vrev.push_back(v[i]);
	}

	return vrev;
}

void vrev_2(vector<string>& v) // reverse elements of a vector, return by reference
{
	for (int i=0, j=v.size()-1; i<j; ++i, --j) {
		swap(v[i], v[j]);
	}
	return;
}
