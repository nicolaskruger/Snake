/*
 * Food.h
 *
 *  Created on: 10 de nov de 2020
 *      Author: nicolas-kruger
 */
#include "Entity.h"
#include "Map.h"
#include "cmsis_os.h"

#ifndef FOOD_H_
#define FOOD_H_

class Food :public Entity{
private:
	osMutexId* mutex;
public:
	bool eated=false;
	Food(osMutexId* mutex);
	virtual ~Food();
	virtual void tick();
	virtual void render();
};

#endif /* FOOD_H_ */
