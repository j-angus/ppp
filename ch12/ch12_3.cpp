/**
 * @file ch12_3.cpp
 * @date 2011-07-24
 */

#include "Simple_window.h"
#include "Graph.h"
#include <FL/Fl_Window.H>

int main()
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib

	Point tl(100,100); // top left corner of widnow
	Simple_window win(tl,600,400,"Canvas"); // make a simple window

	Polygon poly; // make a shape
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));
	poly.set_color(Color::red);

	win.attach(poly); // connect poly to the window

	win.wait_for_button(); // give control to the display engine

	//return Fl::run();
}