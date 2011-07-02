/**
 * @file ch08drill02.cpp
 * @date 2011-07-02
 *
 */

#include "../../std_lib_facilities.h"

/* swap_v doesn't work as intended because swaps are done only on variables
 * local to the function. No changes are mad to the parametrs passed to the function.
 */
// swap by value (copies of paramaters)
void swap_v(int a, int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

// swap using references to parameters
void swap_r(int& a, int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

/* swap_cr() does not compile because it is illegal to try to assign
 * new values to a const variable.
// swap by constant reference parameters
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
*/

int main()
{
	try {
		int x=7;
		int y=9;
		swap_r(x,y);
		cout << "swap_r(x,y)\n" << "x: " << x << ", y: " << y << endl;
		//swap_v(7,9);
		//cout << "swap_r(7,9)\n" << "x: " << x << ", y: " << y << endl;
		const int cx=7;
		const int cy=9;
		// error, can't swap const var by reference
		//swap_r(cx,cy);
		//cout << "swap_r(cx,cy)\n" << "x: " << cx << ", y: " << cy << endl;
		// error, can't swap literal number as a reference to a variable
		//swap_r(7.7,9.9);
		//cout << "swap_r(7.7,9.9)\n" << "x: " << cx << ", y: " << cy << endl;
		double dx=7.7;
		double dy=9.9;
		// error, can't swap ref to dobule, function expects ref to int
		//swap_r(dx,dy);
		//cout << "swap_r(dx,dy)\n" << "x: " << dx << ", y: " << dy << endl;
		//swap_r(dx,dy);
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;

		return 1;
	}
	return 0;
}
