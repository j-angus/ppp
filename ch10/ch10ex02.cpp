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

void create_readings(vector<Reading>& v, uint n); // create a vector of 'n' Readings

int main()
{
	const string ifname="hour_temp_pairs.txt"; // input filename
	const string ofname="raw_temps.txt"; // output filename
	vector<Reading> temps; // store the readings here
	int hour;
	double temperature;

	try {
		//open file for reading
		ifstream ist(ifname.c_str());
		if (!ist) error("can't open input file: ", ifname);
		// make ist throw if it goes bad
		ist.exceptions(ist.exceptions()|ios_base::badbit);

		while (ist >> hour >> temperature) {
			if (hour<0 || 23<hour) error("hour out of range");
				temps.push_back(Reading(hour,temperature)) ;
		}
		if (ist.eof()) cout << "OK: reached eof.\n";
		temps.clear();
		//temps.resize(0);
		create_readings(temps, 100); // just create a bunch of readings, ignore what we just read
		for (uint i=0; i<temps.size(); ++i)
			cout << temps[i].hour << ' ' << temps[i].temperature << endl;
		ofstream ost(ofname.c_str()); //open file for writing
		if (!ost) error("can't open output file: ", ofname);
		for (uint i=0; i<temps.size(); ++i)
			ost << temps[i].hour << ' ' << temps[i].temperature << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}

// create a vector of 'n' Readings
void create_readings(vector<Reading>& v, uint n)
{
	const double low_t = -5.0;
	const double high_t = 30.0;
	double t = low_t;
	const int low_h = 0;
	const int high_h = 23;
	int h = low_h;

	for (uint i=0; i<n; ++i) {
		v.push_back(Reading(h, t));
		t += 0.5; // increment temp
		if (t > high_t) t = low_t;
		++h;
		if (h>high_h) h=low_h;
	}
	cout << "finished filling v\n";
	return;
}
