/**
 * @file ch10drill01.cpp
 * @date 2011-07-04
 *
 * Start a program to work with points, discusscd in § 10.4.
 * Begin by defining the data type Point that has two coordinate members x and y.
 */

#include "../std_lib_facilities.h"

// a class for storing x, y points
struct Point
{
	int x;
	int y;
	void setx(int xx) {x=xx;}
	void sety(int yy) {y=yy;}
	Point() : x(0), y(0) {}
};

// logic operators
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);

// define << operator for Point class
ostream& operator<<(ostream& os, const Point& pt);

int main()
{
	Point pt;
	try {
		cout << pt;
		pt.setx(10);
		pt.sety(10);
		cout << pt;
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
 */


// logic operators
bool operator==(const Point& a, const Point& b)
{
	if ((a.x != b.x) || (a.y!=b.y))
		return false;
	return true;
}

bool operator!=(const Point& a, const Point& b)
{
	return !(a==b);
}

// define << operator for Point class
ostream& operator<<(ostream& os, const Point& pt)
{
	return os << "x: " <<pt.x<< ", y: " << pt.y<<endl;
 }


