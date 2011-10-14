/**
 * @file ch13ex02.cpp
 * @date 2011-08-12
 *
 * 2. Draw a box with rounded corners. Define a class Box, consisting of four
 * lines and four arcs.
 *
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
	Point tl(50,50); // top left corner of window
	Simple_window win(tl,500,500,"ch13ex02"); // make a simple window

	// get the size of the window
	// create a grid
	Lines grid;
	const int g_size = 4; // grid size
	const int g_space = 50; // grid spacing
	// horizonal lines
	for (int x=g_space; x<=g_size*g_space; x+=g_space)
		grid.add(Point(x,0),Point(x,g_size*g_space));
	// vertical lines
	for (int y=g_space; y<=g_size*g_space; y+=g_space)
		grid.add(Point(0,y),Point(g_size*g_space,y));
	win.attach(grid);

	// arc definition based on Circle
	Arc_c arc_c_1(Point(100,200),50,0,90);
	arc_c_1.set_color(Color::red);
	win.attach(arc_c_1);

	Arc_c arc_c_2(Point(100,200),50,90,180);
	arc_c_2.set_color(Color::blue);
	win.attach(arc_c_2);

	Arc_c arc_c_3(Point(100,200),50,180,270);
	arc_c_3.set_color(Color::yellow);
	win.attach(arc_c_3);

	Arc_c arc_c_4(Point(100,200),50,270,360);
	arc_c_4.set_color(Color::green);
	win.attach(arc_c_4);

	Text t_1(Point(5,130),"arcs based on Circle.");
	t_1.set_font(Font::times_bold);
	t_1.set_font_size(16);
	win.attach(t_1);

	// arc definition based on Ellipse
	Arc arc_1(Point(300,200),75,50,0,90);
	arc_1.set_color(Color::red);
	win.attach(arc_1);

	Arc arc_2(Point(300,200),75,50,90,180);
	arc_2.set_color(Color::blue);
	win.attach(arc_2);

	Arc arc_3(Point(300,200),75,50,180,270);
	arc_3.set_color(Color::yellow);
	win.attach(arc_3);

	Arc arc_4(Point(300,200),75,50,270,360);
	arc_4.set_color(Color::green);
	win.attach(arc_4);

	Text t_2(Point(205,130),"arcs based on Ellipse.");
	t_2.set_font(Font::times_bold);
	t_2.set_font_size(16);
	win.attach(t_2);

	Point bp(200,200);

	Box b(Point(200,200),100,250);
	win.attach(b);
	//b.move(100,100);
	Box b1(Point(200,200),125,250);
	win.attach(b1);
	Box b2(Point(200,200),150,250);
	win.attach(b2);
	Box b3(Point(200,200),175,250);
	win.attach(b3);
	Box b4(Point(200,200),200,250);
	win.attach(b4);
	Box b5(Point(200,200),225,250);
	win.attach(b5);
	Box b6(Point(200,200),250,250);
	win.attach(b6);
	Box b7(Point(200,200),275,250);
	win.attach(b7);
	Box b8(Point(200,200),300,250);
	win.attach(b8);
	Box b9(bp, 325,250);
	win.attach(b9);
	Box b10(bp, 350,250);
	win.attach(b10);
	Box b11(bp, 375,250);
	win.attach(b11);
	Box b12(bp, 400,250);
	win.attach(b12);

	win.wait_for_button(); // display

	cout << "We're finished now!\n";

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