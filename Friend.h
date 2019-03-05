#ifndef __Friend_H
#define __Friend_H

#include "Entity.h"

class Friend :public Entity
{

private:

	Date date;

public:

	Friend(char* Name, const Date& date, const Board& board);

	virtual void ConnectEntities(Entity &entity) override;

};

#endif;
