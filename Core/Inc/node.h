/*
 * node.h
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */
#include "Entity.h"
#ifndef NODE_H_
#define NODE_H_

class node :public Entity{
private:
	string val="*";
public:
	node();
	node(string val){this->val = val;}
	node(int px,int py){this->px=px;this->py=py;}
	virtual ~node();
	virtual void render();
	virtual void tick();
};

#endif /* NODE_H_ */
