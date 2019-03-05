#include <iostream>
using namespace std;

#include "Time.h"

Time::Time(int hour, int minutes) throw(const char*)
{
	if (hour < 1 || hour>12)
		throw "Choose valid hour";
	if (minutes < 0 || minutes>59)
		throw "Choose valid minutes";

	this->hour = hour;
	this->minutes = minutes;
}

void Time::print() const
{
	cout << hour << ":" << minutes << endl;
}