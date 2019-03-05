#ifndef __FaceBook_H
#define __FaceBook_H

#include "Entity.h"
#include "Friend.h"

class FaceBook
{
private:

	int  numOfEntities;
	Entity** allEntities;

public:

	FaceBook();
	FaceBook(const FaceBook& other);
	const FaceBook& operator=(const FaceBook& other);
	~FaceBook();

	Entity* getEntity(int i) const;

	void addEntity(Entity& entity);

	void print_allEntities() const;

};

#endif;
