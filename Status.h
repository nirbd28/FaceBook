#pragma warning (disable : 4996)
#ifndef __Status_H
#define __Status_H

#include "Date.h"
#include "Time.h"

class Status{

public:

	enum eType{Text,Picture,Video};
	
private:

	Date date;
	Time time;
	eType type;

	char* content;

public:

	Status(char* content, Date date, Time time, eType type = eType(0));
	Status(const Status& other);
	const Status& operator=(const Status& other);
	~Status();

	char* get_content() const;

	void print() const;

	bool operator==(const Status&other) const;
	bool operator!=(const Status&other) const;

};

#endif