/**
 * @file ch12_7_3.cpp
 * @date 2011-07-24
 */

#include "Simple_window.h"
#include "Graph.h"
#include <FL/Fl_Window.H>

// Use Axis class
int main()
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib

try
{
	Point tl(100,100); // top left corner of window
	Simple_window win(tl,600,400,"Canvas"); // make a simple window

	Axis xa(Axis::x, Point(20,300), 280, 10, "x axis");
			// an Axis is a kind of shape
			// Axis::x means horizontal
			// starting at (20,300)
			// 280 pixels long
			// 10 "notches"
			// label the axis

	Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");

	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	win.attach(ya);
	win.attach(xa); // connect poly to the window
	win.set_label("Canvas #3");
	win.wait_for_button(); // display
}
catch(exception& e) {
	return 1;
}
catch(...) {
	return 2;
}
} // main()