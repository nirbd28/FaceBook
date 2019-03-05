#ifndef __Date_H
#define __Date_H

class Date{

private:

	int year, month, day;
	
public:

	Date(int day=1, int month=1, int year=2000);

	void print() const;

};

#endif;