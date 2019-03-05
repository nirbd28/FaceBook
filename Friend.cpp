#include <iostream>
using namespace std;

#include "Friend.h"

Friend::Friend(char* Name, const Date& date, const Board& board) :Entity(Name, board), date(date){}

void Friend::ConnectEntities(Entity &entity) throw(const char*)
{
	Friend*temp = dynamic_cast<Friend*>(&entity);
	if (!temp)
		throw "Choose a Friend";
	
	if (this==&entity)
		throw "Choose two different friends";

	bool flag = false;
	for (int i = 0; i < numOfEntities; i++)
	{
		if (allEntities[i] == &entity)
		{
			flag = true;
			break;
		}
	}

	if (!flag)
	{
		numOfEntities++;
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
		entity.ConnectEntities(*this);
	}

}



