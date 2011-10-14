/**
 * @file ch12ex02.cpp
 * @date 2011-08-07
 *
 * 2. Draw a 100-by-30 Rectangle and place the text "Howdy!" inside it.
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
	Simple_window win(tl,600,400,"ch12ex02"); // make a simple window

	// Rectangle as a Rectangle
	Rectangle r(Point(200,200),250,30); // top left corner, width, height
	win.attach(r);
	r.set_color(Color::blue); // colour the rectangle

	Text t(Point(205,224),"Howdy!0,;1'l.j:k\"");
	t.set_font(Font::courier);
	t.set_font_size(25);
	win.attach(t);

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