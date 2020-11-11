/*
 * Food.cpp
 *
 *  Created on: 10 de nov de 2020
 *      Author: nicolas-kruger
 */

#include "Food.h"

Food::Food(osMutexId* mutex):Entity() {
	this->mutex= mutex;
	// TODO Auto-generated constructor stub

}

Food::~Food() {
	// TODO Auto-generated destructor stub
}

void Food::tick(){
	if(!eated) return;
	eated = false;
	osMutexWait(*mutex, 100);
	px = rand()%Map::maxX();
	py = rand()%Map::maxY();
	osMutexRelease(*mutex);
}
void Food::render(){
	osMutexWait(*mutex, 100);
	Display::LCD_Write_String_Grid(getX(),getY(), "0");
	osMutexRelease(*mutex);
}
