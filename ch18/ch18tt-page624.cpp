/**
 * @author Jason Angus
 * @file ch18tt-page264.cpp
 * @date 2011-09-09
 * 
 * Try this from PPP page 624.
 * experimenting with class construction / destruction
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

void srcfile_info(); // display basic source file information

struct X { 	// simple test class
	int val;
	string n; // use to set name of class - fo debugging

	X() : val(0), n(""){ out("X(), default constructor."); }	// default constructor
	X(int v, string s) : val(v), n(s){ out("X(int,string), basic constructor."); }
	X(const X& x): val(x.val), n(x.n){ out("X(X&), copy constructor using: " + x.n); }	// copy constructor
	X& operator=(const X& a)	// copy assignment
		{ val=a.val; n=a.n; out("X::operator=(), copy assignment using: " + a.n); return *this; }

	void out(const string& s)
	{ 
		std::cerr << this << "->" << s << endl; 
		std::cerr << "val: " << val << ", " << "n: "<< n << endl;	
	}
	
	void name(const string& s){ n=s; };

	~X(){ out("~X()"); }	// destructor
};

X glob(2,"glob");	// a global variable
X copy(X a){ a.n="copy of: " + a.n; return a; }
X copy2(X a){ X aa=a; aa.n="copy2 of: " + aa.n; return aa; }
X& ref_to(X& a){ a.out("function ref_to() " + a.n); return a; }
X* make(int i, string s){ X a(i,s); return new X(a); }

struct XX { X a; X b; };

int main()
{
	X loc(4,"loc");	// local variable
	X loc2=loc;
	loc=X(5,"loc");
	loc2=copy(loc);
	loc2.name("loc2, copy of loc");
	loc2=copy2(loc);
	loc2.name("loc2, copy2 of loc");
	X loc3(6,"loc3");
	X& r = ref_to(loc);
	delete make(7,"make7");
	delete make(8, "make8");
	vector<X> v(4);
	cout << "vector<X>\n";
	XX loc4;
	cout << "XX loc4\n";
	X* p=new X(9,"p");	// an X on the free store
	delete p;
	X* pp=new X[5];	// an array of X's on the free store
	delete[] pp;

		
	//srcfile_info();
	return 0;
}

void srcfile_info()
{
	cout << "File:\t\t" << __FILE__ << "\n";
	cout << "Compiled:\t" << __DATE__;
	cout << " at " << __TIME__ << "\n\n";
	return;
}

