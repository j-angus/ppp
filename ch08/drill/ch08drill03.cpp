/**
 * @file ch08drill03.cpp
 * @date 2011-07-02
 *
 */

#include "../../std_lib_facilities.h"

namespace X {
	int var;
	void print()
	{
		cout << "X::var: " << var << endl;
		return;
	}
}
namespace Y {
	int var;
	void print()
	{
		cout << "Y::var: " << var << endl;
		return;
	}
}

namespace Z {
	int var;
	void print()
	{
		cout << "Z::var: " << var << endl;
		return;
	}
}

int main()
{
	try {
		X::var = 7;
		X::print();			// print X's var
		using namespace Y;
		var = 9;
		print();			// print Y's var
		{
			using Z::var;
			using Z::print;
			var = 11;
			print();		// print Z's var
		}
		print();			// print Y's var
		X::print();			// print X's var
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;

		return 1;
	}
	return 0;
}
