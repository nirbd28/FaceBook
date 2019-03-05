#pragma warning (disable : 4996)
#ifndef __Entity_H
#define __Entity_H

#include "Board.h"

class Entity
{
protected:

	int serialNum;
	char *Name;
	Entity** allEntities;
	int  numOfEntities;
	Board board;
	
public:

	Entity(char* Name, const Board& board);
	Entity(const Entity& other);
	const Entity& operator=(const Entity& other);
	~Entity();

	void addStatus(Status &status);

	virtual void ConnectEntities(Entity &entity) = 0;

	char* get_Name() const;
	int get_serialNum() const;
	int get_numOfEntities() const;

	void update_serialNum(int serialNum);

	void print() const;
	void print_allEntities() const;
	void print_allStatus() const;

	bool operator>(const Entity&other) const;

	void operator+=(Entity&other);

};

#endif;
