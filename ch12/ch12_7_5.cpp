/**
 * @file ch12_7_5.cpp
 * @date 2011-07-24
 */

#include "Simple_window.h"
#include "Graph.h"
#include <FL/Fl_Window.H>

// 12.7.5 polygons
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

	Function sine(sin,0,100,Point(20,150),1000,50,50); // sine curve
		// plot sin() int the range[0:100) with (0,0) at (20,50)
		// using 1000 points; scale x values *50, scale y values *50
	sine.set_color(Color::blue);

	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);

	win.attach(poly);
	win.attach(sine);
	win.attach(ya);
	win.attach(xa); // connect poly to the window
	win.set_label("Canvas #5");
	win.wait_for_button(); // display
}
catch(exception& e) {
	return 1;
}
catch(...) {
	return 2;
}
} // main()