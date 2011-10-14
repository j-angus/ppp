/**
 * @file ch12ex05.cpp
 * @date 2011-08-08
 *
 * 5. Draw a red 1/4-inch frame around a rectangle that is three-quarters
 * the height of your screen and two-thirds the width.
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
	int win_w = 600; // window width
	int win_h = 400; // window height

	Simple_window win(tl,win_w,win_h,"ch12ex05"); // make a simple window

	// calc co-ordinates to centralise 'r' within window
	//int r_x = (win_w - (win_w/4 * 3))/2;
	//int r_y = (win_h - (win_h/3 * 2))/2;
	int r_x = (x_max() - (x_max()/4 * 3))/2;
	int r_y = (y_max() - (y_max()/3 * 2))/2;
	Rectangle r(Point(r_x,r_y),x_max()/4 * 3, y_max()/3 * 2);
	win.attach(r);

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