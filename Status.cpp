#include <iostream>
using namespace std;

#include "Status.h"

const char* Type[] = { "Text", "Picture", "Video" };

Status::Status(char* content, Date date, Time time, Status::eType type) throw(const char*)
{
	if (type != 0 && type != 1 && type != 2)
		throw "Choose valid type";

	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);
	this->type = type;
	this->date = date;
	this->time = time;
}

Status::Status(const Status& other) :date(other.date), time(other.time)
{
	*this = other;
}

const Status& Status::operator=(const Status& other) 
{
	if (this != &other)
	{
		this->content = new char[strlen(other.content) + 1];
		strcpy(this->content, other.content);
		this->type = other.type;
		this->date = other.date;
		this->time = other.time;
	}
	return *this;
}

Status::~Status()
{
	delete[]content;
}

char* Status::get_content() const
{
	return content;
}

void Status::print() const
{
	cout << "Date:";
	date.print();
	cout << "Time:";
	time.print();
	cout << "Type:" << Type[type] << endl;	
	cout << "Content:" << content << endl;
}

bool Status::operator==(const Status&other) const
{
	bool flag = strcmp(content, other.content);
	return !flag;
}

bool Status::operator!=(const Status&other) const
{
	bool flag = strcmp(content, other.content);
	return flag;
}

