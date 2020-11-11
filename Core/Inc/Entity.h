/*
 * Entity.h
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */
#include "Map.h"
#include "Display.h"
#include <string>
using namespace std;
#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
protected:

public:
	double px=0;
	double py=0;
	int getX(){return px;}
	int getY(){return py;}
	virtual bool colidin(Entity *ohter);
	virtual void tick()=0;
	virtual void render()=0;
	Entity();
	virtual ~Entity();
};

#endif /* ENTITY_H_ */
