/**
 * @file ch10drill02.cpp
 * @date 2011-07-04
 *
 * 1. Start a program to work with points, discusscd in § 10.4.
 * Begin by defining the data type Point that has two coordinate members x and y.
 * 2. Using the code and discussion in §10.4, prompt the user to input seven
 * (x,y) pairs. As the data is entered, store it in a vector of Points called original_points.
 */

#include "../std_lib_facilities.h"

// a class for storing x, y points
struct Point {
	int x;
	int y;
	Point(int xx, int yy) : x(xx), y(yy) {}
	Point() : x(0), y(0) {}
};

// logic operators
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);

// define << operator for Point class
ostream& operator<<(ostream& os, const Point& pt);

int main()
{
	const int loop=7;
	int ptx, pty; // hold user input
	vector<Point> original_points(loop);
	try {
		for (int i=0; i<loop; ++i) {
			cout << "Enter a pair of integer points(x y): ";
			cin >> ptx >> pty;
			// check that input is valid here
			original_points.push_back(Point(ptx, pty));
		}
		for (int i=0; i<loop; ++i) {
			//cout << "original_points["<<i<<"].x: "<<original_points[i].x<<
			//", original_points["<<i<<"].y: "<<original_points[i].y<<endl;
			cout << "original_points["<<i<<"] "<<original_points[i];
		}
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


