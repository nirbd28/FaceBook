#ifndef __Time_H
#define __Time_H

class Time{

private:

	int hour, minutes;

public:

	Time(int hour=1, int minutes=0);

	void print() const;

};

#endif