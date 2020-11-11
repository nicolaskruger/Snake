/*
 * node.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */

#include "node.h"

node::node():Entity() {
	// TODO Auto-generated constructor stub

}

node::~node() {
	// TODO Auto-generated destructor stub
}
void node::render(){
	Display::LCD_Write_String_Grid(getX(), getY(), val);
}
void node::tick(){

}
