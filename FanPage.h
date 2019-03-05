#ifndef __FanPage_H
#define __FanPage_H

#include "Entity.h"
#include "Friend.h"

class FanPage :public Entity
{

private:

public:

	FanPage(char* Name, const Board& board);

	virtual void ConnectEntities(Entity &entity) override;

	void removeFriend(Entity &entity);
};

#endif;
