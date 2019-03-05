#include <iostream>
using namespace std;

#include "FanPage.h"

FanPage::FanPage(char* Name, const Board& board) :Entity(Name, board){}

void FanPage::ConnectEntities(Entity &entity) throw(const char*)
{
	Friend*temp = dynamic_cast<Friend*>(&entity);
	if (!temp)
		throw "Choose Friend";

	bool flag = false;
	int i;
	for (i = 0; i < numOfEntities; i++)
	{
		if (allEntities[i] == &entity)
		{
			flag = true;
			break;
		}
	}

	if (flag == true)
		throw "Friend is a fan already";


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
}

void FanPage::removeFriend(Entity &entity) throw(const char*)
{
	Friend*temp = dynamic_cast<Friend*>(&entity);
	if (!temp)
		throw "Choose a Friend";

	bool flag = false;
	int i;
	for (i = 0; i < numOfEntities; i++)
	{
		if (allEntities[i] == &entity)
		{
			flag = true;
			break;
		}
	}

	if (flag == false)
		throw "Selected Friend is not a fan";
	else
	{
		Entity* temp_last = allEntities[numOfEntities - 1];
		numOfEntities--;

		Entity**temp = new Entity*[numOfEntities];
		for (int i = 0; i < numOfEntities; i++)
			temp[i] = allEntities[i];
		allEntities = new Entity*[numOfEntities];
		for (int i = 0; i < numOfEntities; i++)
			allEntities[i] = temp[i];
		delete[]temp;

		if (i != numOfEntities)
		{
			allEntities[i] = nullptr;
			allEntities[i] = temp_last;
		}	
	}
}



