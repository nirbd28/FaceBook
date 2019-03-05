#include <iostream>
using namespace std;

#include "Entity.h"

Entity::Entity(char* Name, const Board& board) 
{
	serialNum = 0;
	numOfEntities = 0;
	this->Name = new char[strlen(Name) + 1];
	strcpy(this->Name, Name);
	this->board = board;
}

Entity::Entity(const Entity& other) :board(other.board)
{
	*this = other;
}
const Entity& Entity::operator=(const Entity& other)
{
	if (this != &other)
	{
		serialNum = 0;
		Name = strdup(other.Name);
		board = other.board;
		numOfEntities = other.numOfEntities;
		allEntities = new Entity*[numOfEntities];
		if (numOfEntities > 0)
		{
			for (int i = 0; i < numOfEntities; i++)
				allEntities[i] = other.allEntities[i];
		}
	}
	return *this;
}

Entity::~Entity()
{
	delete[]Name;
	if (numOfEntities > 0)
		delete[]allEntities;
}

void Entity::addStatus(Status &status)
{
	this->board.addStatus(&status);
}


char* Entity::get_Name() const
{
	return Name;
}

int Entity::get_serialNum() const
{
	return serialNum;
}

int Entity::get_numOfEntities() const
{
	return numOfEntities;
}

void Entity::update_serialNum(int serialNum = 0)
{
	this->serialNum = serialNum;
}

void Entity::print() const
{
	cout << "Name:" << Name << endl;
	cout << endl;
}

void Entity::print_allStatus() const
{
	board.print_allStatus();
}

void Entity::print_allEntities()const
{
	for (int i = 0; i < numOfEntities; i++)
		allEntities[i]->print();
}

bool Entity::operator>(const Entity&other) const
{
	if (numOfEntities > other.numOfEntities)
		return true;
	return false;
}

void Entity::operator+=(Entity&other)
{
	this->ConnectEntities(other);
}



