/**
 * @file ch14drill.cpp
 * @date 2011-08-14
 *
 * drill exercises from page 505
 */

#include <stdexcept>
#include <FL/Fl_Window.H>
#include "Simple_window.h"
#include "Graph.h"

class B1 {
public:
	virtual void pvf() =0;
	virtual void const vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
};

class B2 {
public:
	virtual void pvf() =0;
};

class D1 : public B1 {
public:
	void pvf() { cout << "D1::pvf()\n"; }
	void const vf() { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
};

class D2 : public D1 {
public:
	void pvf() { cout << "D2::pvf()\n"; }
	//void const vf() { cout << "D1::vf()\n"; }
	//void f() { cout << "D1::f()\n"; }
};

class D21 : public B2 {
public:
	D21 (string ss) : s(ss) {}
	void pvf() { cout << "D21::pvf(), D21::s: " << s << endl; }
private:
	string s;
};

class D22 : public B2 {
public:
	D22 (int ii) : i(ii) {}
	void pvf() { cout << "D22::pvf(), D22::i: " << i << endl; }
private:
	int i;
};

void call(B1& b1)
{
	b1.pvf();
	b1.vf();
	b1.f();
}
void f(B2& b2)
{
	b2.pvf();
}

int main()
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib

try
{
	Point tl(250,50); // top left corner of window
	Simple_window win(tl,50,50,"ch14drill"); // make a simple window

//	B1 b1;
//	b1.vf();
//	b1.f();

	D1 d1;
	d1.pvf();
	d1.vf();
	d1.f();

	call(d1);

	D2 d2;
	d2.pvf();
	d2.vf();
	d2.f();

	D21 d21("class d21");
	D22 d22(22);

	f(d21);
	f(d22);

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