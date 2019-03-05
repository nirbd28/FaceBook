#include <iostream>
using namespace std;

#include "Board.h"

Board::Board(bool editByFriends) throw(const char*)
{
	if (editByFriends != true && editByFriends != false)
		throw "Enter valid deatails";

	this->editByFriends = editByFriends;
	numOfStatus = 0;
}

Board::Board(const Board& other)
{
	*this = other;
}
const Board& Board::operator=(const Board& other)
{
	if (this!=&other)
	{
		numOfStatus = other.numOfStatus;
		editByFriends = other.editByFriends;
		allStatus = new Status*[numOfStatus];
		if (numOfStatus > 0)
		{
			for (int i = 0; i < numOfStatus; i++)
				allStatus[i] = other.allStatus[i];
		}
	}
	return *this;
}

Board::~Board()
{
	if (numOfStatus > 0)
	{
		for (int i = 0; i < numOfStatus; i++)
			delete allStatus[i];
		delete[]allStatus;
	}
}

void Board::addStatus(Status *status) 
{
	numOfStatus++;
	if (numOfStatus > 1)
	{
		Status**temp = new Status*[numOfStatus - 1];
		for (int i = 0; i < numOfStatus; i++)
			temp[i] = allStatus[i];
		allStatus = new Status*[numOfStatus];
		for (int i = 0; i < numOfStatus; i++)
			allStatus[i] = temp[i];
		delete[]temp;
	}
	else
	{
		allStatus = new Status*[numOfStatus];
	}
	allStatus[numOfStatus - 1] = status;
}

void Board::print_allStatus() const
{
	for (int i = 0; i < numOfStatus; i++)
	{
		cout << endl;
		allStatus[i]->print();
		cout << endl;
	}
}