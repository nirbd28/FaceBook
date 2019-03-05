#include <iostream>
using namespace std;

#include "Date.h"

Date::Date(int day, int month, int year) throw(const char*)
{
	if (day < 1 || day>31)
		throw "Choose valid day";
	if (month < 1 || month>12)
		throw "Choose valid month";
	if (year < 1990 || year>2100)
		throw "Choose valid year(1990-2100)";

	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::print() const
{
	cout << day << "/" << month << "/" << year << endl;
}