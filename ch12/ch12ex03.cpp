/**
 * @file ch12ex03.cpp
 * @date 2011-08-07
 *
 * 3. Draw your initials 150 pixels high. Use a thick line. Draw each initial
 * in a different color.
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
	Simple_window win(tl,600,400,"ch12ex03"); // make a simple window

	// draw initial 'J'
	Line init_J1(Point(100,50),Point(250,50));
	init_J1.set_color(Color::red);
	init_J1.set_style(Line_style(Line_style::solid,10));
	win.attach(init_J1); // connect poly to the window

	Line init_J2(Point(175,50),Point(175,175));
	init_J2.set_color(Color::red);
	init_J2.set_style(Line_style(Line_style::solid,10));
	win.attach(init_J2); // connect poly to the window

	Open_polyline init_J3;
	init_J3.add(Point(175,175));
	init_J3.add(Point(155,200));
	init_J3.add(Point(120,200));
	init_J3.add(Point(100,175));
	init_J3.set_color(Color::red);
	init_J3.set_style(Line_style(Line_style::solid,10));
	win.attach(init_J3); // connect poly to the window

	// draw initial 'A'
	Open_polyline init_J4;
	init_J4.add(Point(300,200));
	init_J4.add(Point(350,50));
	init_J4.add(Point(400,200));
	init_J4.add(Point(382,150));
	init_J4.add(Point(320,150));
	init_J4.set_color(Color::blue);
	init_J4.set_style(Line_style(Line_style::solid,10));
	win.attach(init_J4); // connect poly to the window

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