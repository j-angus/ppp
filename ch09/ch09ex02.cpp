/**
 * @file ch09ex02.cpp
 * @date 2011-07-02
 *
 * Design and implement a Name_pairs class holding (name,age) pairs where name is a
 * string and age is a double.
 * Represent as vector<string> name, vector<double> age members.
 * Provide an input operation read_names() that reads a series of names.
 * Provide a read_ages() operation that prompts the user for an age for each name.
 * Provide a print() operation that prints out (name[i], age[i]) pairs (one per line) in
 * the order determined by the name vector.
 * Provide a sort() operation that sorts the name vector in alphabetical order and
 * re-organises the age vector to match.
 * Implement all "operations" as member functions.
 */

#include "../std_lib_facilities.h"

// a class for storing and organising name/age pairs
class Name_pairs
{
	public:
		Name_pairs(); // default constructor

		// modifying operations
		void read_names();
		void read_ages();
		void sort();

		// non-modifying operations
		void print();
		string get_name(uint i) const { return name[i]; }
		double get_age(uint i) const { return age[i]; }
		uint get_name_size() const {return name.size();}
		uint get_age_size() const {return age.size();}

	private:
		vector<string> name;
		vector<double> age;
		const string quit;
};

// logic operators
bool operator==(const Name_pairs& a, const Name_pairs& b);
bool operator!=(const Name_pairs& a, const Name_pairs& b);

// define << operator for Name_pairs class
ostream& operator<<(ostream& os, const Name_pairs& np);

int main()
{
	Name_pairs npr;
	try {
		npr.read_names();
		npr.read_ages();
		//npr.print();
		cout << npr;
		npr.sort();
		//npr.print();
		cout << npr;
		Name_pairs npr2 = npr;
		cout << ((npr2==npr) ? "true" : "false") << endl;
		Name_pairs npr3;
		npr3.read_names();
		npr3.read_ages();
		cout << ((npr3==npr) ? "true" : "false") << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;

		return 1;
	}
	return 0;
}


// member function definitions

/**
 * default constructor
 * set the quit character for entering names
 */
Name_pairs::Name_pairs()
	:quit("#")
{
	cout << "DEBUG: Name_pairs()\n";
}

/**
 * Read a series of names from a user.
 */
void Name_pairs::read_names()
{
	cout << "DEBUG: read_names()\n";
	string n; // store user input for name
	do {
		cout << "Please enter a name ('"<<quit<< "' to quit): ";
		cin >> n;
		if (n==quit)
			break;
		name.push_back(n);
	} while (true);

	return;
}

/**
 * Read a series of ages corresponding to
 * names from a user.
 */
void Name_pairs::read_ages()
{
	cout << "DEBUG: read_ages()\n";
	double a; // hold age entered by user

	for (uint i=0; i<name.size(); ++i) {
		cout << "Enter age for "<<name[i]<<": ";
		cin >> a;
		age.push_back(a);
	}
	return;
}

/**
 * Print the contents of the name and age vector pairs, one per line.
 */
void Name_pairs::print()
{
	cout << "DEBUG: print()\n";
	// check that vectors have an equal number of entries
	if (name.size() != age.size())
		error("name and age have different number of entries.");
	for (uint i=0; i<name.size(); ++i)
		cout << "person[" << i << "] name: " << name[i] << ", age: " << age[i] << endl;
	return;
}

/**
 * sort the name and age vectors according to name alphabetical order
 */
void Name_pairs::sort()
{
	cout << "DEBUG: sort()\n";
	// copy vectors before sorting so we can sort age to correspond to the sorted order of name
	vector<string> old_name_order = name;
	vector<double> old_age = age;

	// check that vectors have an equal number of entries
	if (name.size() != age.size())
		error("name and age have different number of entries.");
	std::sort(name.begin(), name.end());
	if (old_name_order == name) // no change in order of name
		return;
	// sort age to correspond to new sorted order of name
	for (uint i=0; i<old_name_order.size(); ++i){
		for (uint j=0; j<name.size(); ++j) {
			if (old_name_order[i] == name[j]) {
				age[j]=old_age[i];
				break;
			}
		}
	}
	return;
}


// logic operators
bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	if ((a.get_name_size() != b.get_name_size())	||
		(a.get_age_size() != b.get_age_size())	||
		(a.get_name_size() != b.get_age_size()))
		return false;
	for (uint i=0; i<a.get_name_size(); ++i) {
		if (a.get_name(i) != b.get_name(i))
			return false;
		if (a.get_age(i) != b.get_age(i))
			return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a==b);
}

// define << operator for Name_pairs class
ostream& operator<<(ostream& os, const Name_pairs& np)
{
	for (uint i=0; i<np.get_name_size(); ++i)
		cout << "entry[" <<i<< "] name: " <<np.get_name(i)<< ", age: " <<np.get_age(i)<< endl;
	return os;
 }


