/**
 * @file ch10ex02.cpp
 * @date 2011-07-05
 *
 * 2. Write a program that creates a file of data in the form of the temperature
 * Reading type defined in § 10.5. Fill the file with at least 50 temperature
 * readings. Call this program store_temps.cpp and the file it creates
 * raw_temps.txt.
 */

#include "../std_lib_facilities.h"

struct Reading {			// a temperature reading
	int hour;				// hour after midnight 10:231
	double temperature ;	// in Fahrenheit
	Reading(int h, double t) :hour(h), temperature(t) { }
};

int main()
{
	const string ifname="hour_temp_pairs.txt"; // input filename
	const string ofname="raw_temps.txt"; // output filename
	vector<Reading> temps; // store the readings here
	int hour;
	double temperature;

	try {
		ifstream ist(ifname.c_str()); //open file for reading
		if (!ist) error("can't open input file: ", ifname);
		while (ist >> hour >> temperature) {
			if (hour<0 || 23<hour) error("hour out of range");
				temps.push_back(Reading(hour,temperature)) ;
		}
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}


