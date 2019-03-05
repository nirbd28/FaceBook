#ifndef __Board_H
#define __Board_H

#include "Status.h"

class Board{

private:

	bool editByFriends;
	Status** allStatus;
	int numOfStatus;
	
public:

	Board(bool editByFriends=true);
	Board(const Board& other);
	const Board& operator=(const Board& other);
	~Board();

	void addStatus(Status *status);

	void print_allStatus() const;

};

#endif