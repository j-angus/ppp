/**
 * @file ch12ex04.cpp
 * @date 2011-08-08
 *
 * 4. Draw a checkers board: 8-by-8 alternating white and red squares.
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
	Simple_window win(tl,600,400,"ch12ex04"); // make a simple window

	Shape* r[8]; // an array of shapes for storing Rectangle objects

	vector<Shape*> board;
	int origin_x = 50;
	int origin_y = 50;
	for (int i=0;i<8;++i) {
		r[i] = new Rectangle(Point(origin_x,origin_y),50,50);
		if (i%2) {
			r[i]->set_color(Color::red);
			r[i]->set_fill_color(Color::red);
		}
		else {
			r[i]->set_color(Color::white);
			r[i]->set_fill_color(Color::white);
		}
		board.push_back(new Rectangle(Point(origin_x,origin_y+50),50,50));
		if (!(i%2)) {
			board[i]->set_color(Color::red);
			board[i]->set_fill_color(Color::red);
		}
		else {
			board[i]->set_color(Color::white);
			board[i]->set_fill_color(Color::white);
		}

		win.attach(*r[i]);
		win.attach(*board[i]);
		origin_x+=50;
		//board.push_back(r);
	}

/*
	Rectangle r1(Point(origin,50),50,50);
	r1.set_color(Color::red);
	r1.set_fill_color(Color::red);
	win.attach(r1);

	origin+=50;
	Rectangle w1(Point(origin,50),50,50);
	w1.set_color(Color::white);
	w1.set_fill_color(Color::white);
	win.attach(w1);

	origin+=50;
	Rectangle r2(Point(origin,50),50,50);
	r2.set_color(Color::red);
	r2.set_fill_color(Color::red);
	win.attach(r2);

	origin+=50;
	Rectangle w2(Point(origin,50),50,50);
	w2.set_color(Color::white);
	w2.set_fill_color(Color::white);
	win.attach(w2);

	origin+=50;
	Rectangle r3(Point(origin,50),50,50);
	r3.set_color(Color::red);
	r3.set_fill_color(Color::red);
	win.attach(r3);

	origin+=50;
	Rectangle w3(Point(origin,50),50,50);
	w3.set_color(Color::white);
	w3.set_fill_color(Color::white);
	win.attach(w3);

	origin+=50;
	Rectangle r4(Point(origin,50),50,50);
	r4.set_color(Color::red);
	r4.set_fill_color(Color::red);
	win.attach(r4);

	origin+=50;
	Rectangle w4(Point(origin,50),50,50);
	w4.set_color(Color::white);
	w4.set_fill_color(Color::white);
	win.attach(w4);
/*
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
*/

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