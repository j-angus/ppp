/**
 * @file ch13drill.cpp
 * @date 2011-08-12
 *
 * drill exercises from page 476
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
	Simple_window win(tl,500,500,"ch13drill"); // make a simple window

	// get the size of the window
	// create a grid
	Lines grid;
	const int g_size = 8; // grid size
	const int g_space = 50; // grid spacing
	// horizonal lines
	for (int x=g_space; x<=g_size*g_space; x+=g_space)
		grid.add(Point(x,0),Point(x,g_size*g_space));
	// vertical lines
	for (int y=g_space; y<=g_size*g_space; y+=g_space)
		grid.add(Point(0,y),Point(g_size*g_space,y));
	win.attach(grid);
	// create a diagonal row of red squares
	Vector_ref<Rectangle> vr;
	for (int i=0; i<g_size; ++i) {
		vr.push_back(new Rectangle(Point(g_space*i,g_space*i),g_space,g_space));
		vr[i].set_color(Color::invisible);
		vr[i].set_fill_color(Color::red);
		win.attach(vr[vr.size()-1]);
	}

	// place some images onto the grid
	Image img_1(Point(0,300),"image.jpg");
	img_1.set_mask(Point(325,50),50,50);
	win.attach(img_1);

	Image img_2(Point(0,350),"image.jpg");
	img_2.set_mask(Point(300,65),50,50);
	win.attach(img_2);

	Image img_3(Point(50,350),"image.jpg");
	img_3.set_mask(Point(275,100),50,50);
	win.attach(img_3);

	Image img_4(Point(50,0),"image2.jpg");
	img_4.set_mask(Point(285,100),25,25);
	win.attach(img_4);

	for (int i=0; i<4; ++i) {
		win.wait_for_button(); // display
		img_4.move(28,0);
	}
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