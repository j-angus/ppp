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
	Simple_window win(tl,600,500,"ch12ex04"); // make a simple window

	vector<Shape*> board; // a vector of shapes for storing Rectangle objects
	int origin_x = 50; // starting position for drawing checkers
	int origin_y = 50;
	int x = origin_x;
	int y = origin_y;
	int w = 50; // checker width
	int h = 50; // checker height
	Color c(Color::red); // checker colour

	for (int row=0;row<8;++row) {
		for (int col=0;col<8;++col) {
			board.push_back(new Rectangle(Point(x,y),w,h));
			// alternate colour of checkers
			if ((row%2) ? col%2 : !(col%2)) {
				c = Color::red;
			}
			else {
				c = Color::white;
			}
			board[(row*8)+col]->set_color(c);
			board[(row*8)+col]->set_fill_color(c);

			win.attach(*board[(row*8)+col]);
			x+=w; // increment square position horizontally
		}
		// increment to next row
		x=origin_x;
		y+=h;
	}

	win.wait_for_button(); // display
	// delete checker objects here...
	for (size_t i=0; i<board.size(); ++i) {
		cout << "deleting board[" << i << "]\n";
		delete board[i];
	}
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