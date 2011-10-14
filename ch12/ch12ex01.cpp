/**
 * @file ch12ex01.cpp
 * @date 2011-08-07
 *
 * 1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the
 * Polygon red and the lines of the Rectangle blue.
 */

#include <stdexcept>
#include <FL/Fl_Window.H>
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib

try
{
	Point tl(100,100); // top left corner of window
	Simple_window win(tl,600,400,"ch12ex01"); // make a simple window
	// win.set_label("Canvas #12");

	// Rectangle as a polygon
	Polygon poly;
	poly.add(Point(50,50));
	poly.add(Point(350,50));
	poly.add(Point(350,150));
	poly.add(Point(50,150));
	poly.set_color(Color::red);
	win.attach(poly); // connect poly to the window

	// Rectangle as a Rectangle
	Rectangle r(Point(200,200),300,100); // top left corner, width, height
	win.attach(r);
	r.set_color(Color::blue); // colour the rectangle

	win.wait_for_button(); // display
}
catch(exception& e) {
	cerr <<"exception: " << e.what() << endl;
	return 1;
}
catch(...) {
	cerr << "Some exception\n";
	return 2;
}
} // main()