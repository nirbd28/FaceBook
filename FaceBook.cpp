#include <iostream>
using namespace std;

#include "FaceBook.h"

FaceBook::FaceBook()
{
	numOfEntities = 0;
}

FaceBook::FaceBook(const FaceBook& other)
{
	*this = other;
}

const FaceBook& FaceBook::operator=(const FaceBook& other)
{
	if (this != &other)
	{
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

FaceBook::~FaceBook()
{
	if (numOfEntities > 0)
	{
		for (int i = 0; i < numOfEntities; i++)
			delete allEntities[i];
		delete[]allEntities;
	}	
}

Entity* FaceBook::getEntity(int i) const throw(const char*)
{
	if (numOfEntities == 0)
		throw "No Entities in faceBook";
	if (i>numOfEntities-1)
		throw "Choose valid Index";
	if (i<0)
		throw "Choose valid Index";
	return allEntities[i];
}

void FaceBook::addEntity(Entity &entity)
{
	numOfEntities++;
	entity.update_serialNum(numOfEntities);
	if (numOfEntities > 1)
	{	
		Entity**temp = new Entity*[numOfEntities - 1];
		for (int i = 0; i < numOfEntities; i++)
			temp[i] = allEntities[i];
		allEntities = new Entity*[numOfEntities];
		for (int i = 0; i < numOfEntities; i++)
			allEntities[i] = temp[i];
		delete[]temp;
	}
	else
	{
		allEntities = new Entity*[numOfEntities];
	}
	allEntities[numOfEntities - 1] = &entity;
}

void FaceBook::print_allEntities() const
{
	for (int i = 0; i < numOfEntities; i++)
	{
		Friend*temp = dynamic_cast<Friend*>(allEntities[i]);
		if (temp)
			cout << "Entity # " << allEntities[i]->get_serialNum() <<" Friend: " << endl;
		else
			cout << "Entity # " << allEntities[i]->get_serialNum() <<" FanPage: " << endl;
		allEntities[i]->print();
	}
}


