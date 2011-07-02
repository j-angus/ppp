/**
 * @file ch08ex07.cpp
 * @date 2011-07-02
 *
 * Read names into vector<string> name
 * Read ages corresponding to names into vector<int> age
 * Print out name[i], age[i] pairs
 * Sort name vector
 * Sort age vector to align with name vector
 * Print the sorted vectors
 */


#include "../std_lib_facilities.h"

void print(const vector<string>& v, string label); // print vector of strings to cout

int main()
{
	vector<string> name; // name
	string name_in; // temporary string to hold user entered value
	vector<int> age; // age corresponding to name
	int age_in; // temporary int to hold user entered value
	const int loop = 5; // how may times to loop
	try {
		for (int i = 0; i<loop; ++i) {
			cout << "Enter a name: ";
			cin >> name_in;
			name.push_back(name_in);
			cout << "Enter " << name[i] << "'s age: ";
			cin >> age_in;
			age.push_back(age_in);
		}
		for (int i = 0; i<loop; ++i)
			cout << name[i] << ", " << age[i] << endl;
		cout << endl;
		// make copies of vectors so we can sort age to match up with name after it is sorted
		vector<string> old_name_order = name;
		vector<int> old_age = age;
		sort(name.begin(), name.end());
		// sort age to match up with name
		if (old_name_order != name) { // only sort if the order of name has changed
			for (int i=0; i<old_name_order.size(); ++i) {
				for (int j=0; j<name.size(); ++j) {
					cout << "i: " << i << ", j: " << j << endl;
					if (old_name_order[i] == name[j]) {
						age[j] = old_age[i];
						cout << "found match\n";
						break;
					}
				}
			}
		}
		cout << "After sorting the names and ages:\n";
		for (int i = 0; i<loop; ++i)
			cout << name[i] << ", " << age[i] << endl;
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

