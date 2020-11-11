/*
 * Entity.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */

#include "Entity.h"

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}
bool Entity::colidin(Entity* other){
	return this->px==other->px&&this->py==other->py;
}
