/*
 * Snake.h
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */
#include "Entity.h"
#include "node.h"
#include "Controller.h"
#include "Food.h"
#include "cmsis_os.h"
#include <vector>
#ifndef SNAKE_H_
#define SNAKE_H_

class Snake :public Entity{
private:
	osMutexId* mutex;
	float next(float cur,float dc,int max);
	float nextX(){return next(snk[0].px, dx, Map::maxX());}
	float nextY(){return next(snk[0].py, dy, Map::maxY());}
	double dy=1;
	double dx=0;
	int currDir=1;
	int cont = 0;
	Food* food;
	vector<node> dir;
	vector<node> snk;
	void resetGame();
	bool autoBite();
	void eatFood();
public:
	Snake();
	Snake(Food * f,osMutexId * mutex);
	virtual void tick();
	virtual void render();
	virtual ~Snake();
};

#endif /* SNAKE_H_ */
