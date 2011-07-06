/**
 * @file ch10ex03.cpp
 * @date 2011-07-05
 *
 * 3. Write a program that reads the data from raw_temps.txt created in
 * exercise 2 into a vector and then calculates the mean and median
 * temperatures in your data set.
 */

#include "../std_lib_facilities.h"

struct Reading {			// a temperature reading
	int hour;				// hour after midnight 10:231
	double temperature ;	// in Fahrenheit
	Reading(int h, double t) :hour(h), temperature(t) { }
};

int main()
{
	const string ifname="raw_temps.txt"; // input filename
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
		double avg=0;
		double total=0;
		double high = -300.0; // less than abs zero;
		double low;
		double median;
		for (uint i=0; i<temps.size(); ++i) {
			total+=temps[i].temperature;
			if (temps[i].temperature > high)
				high = temps[i].temperature;
		}
		low = high;
		for (uint i=0; i<temps.size(); ++i)
			if (temps[i].temperature < low)
				low = temps[i].temperature;

		avg = total/temps.size();
		cout << "average temperature: " << avg << endl;
		median = (low + (high - low)) / 2.0;
		cout << "median temperature: " << median << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		return 1;
	}
	return 0;
}

