/**
 * @file ch08ex08.cpp
 * @date 2011-07-02
 *
 * Write a function randint() that produces a pseudo-random number in the
 * range [0:MAXINT]
 * Taken from Knuth, The Art of Computer Programming, Vol 2 (3E), ch3.6, page 185
 */

#include <limits>
#include "../std_lib_facilities.h"

int my_randint(long x); // produce a pseudo random integer given 0<x && x<2147483647

int main()
{
	int seed=1;
	cout << "seed: " << seed << endl;
	try {
		cout << "my_randint(" << seed <<"): " << my_randint(seed) << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;

		return 1;
}
	return 0;
}

// produce a pseudo random integer given 0<x && x<2147483647
int my_randint(long x)
{
	#define MM 2147483647 // a Mersenne prime
	#define AA 48271	// does well in the spectral test
	#define QQ 44488	// MM / AA
	#define RR 3399	// MM % AA; it is important that RR<QQ

	x = AA*(x%QQ)-RR*(x/QQ);
	if (x<0)
		x+=MM;
	// return x;

	// add more random numbers (page 186)
	#define MMM 214783399	// a non-Mersenne prime
	#define AAA 40692		// good spectral success
	#define QQQ 52774		// MMM / AAA
	#define RRR 3791		// MMM % AAA; again less than QQQ

	long y = AAA*(y%QQQ)-RRR*(y/QQQ);
	if (y<0)
		y+=MMM;
	int z=x-y;
	if (z<0)
		z+=MM;

	cout << "z / " << numeric_limits<int>::max() << ": " << z / (1.0 * numeric_limits<int>::min()) << endl;
	return z;
}
