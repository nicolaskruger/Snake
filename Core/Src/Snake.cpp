/*
 * Snake.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */

#include "Snake.h"

Snake::Snake() :Entity(){
	// TODO Auto-generated constructor stub
	dir = {
			node(0,-1),
			node(1,0),
			node(0,1),
			node(-1,0),
	};

	snk.push_back(node("@"));
	snk.push_back(node(0,1));
	snk.push_back(node(0,2));


}
Snake::Snake(Food * f,osMutexId * mutex){
	this->mutex = mutex;
	this->food=f;
	dir = {
				node(0,-1),
				node(1,0),
				node(0,1),
				node(-1,0),
		};

		snk.push_back(node("#"));
		snk.push_back(node(0,1));
		snk.push_back(node(0,2));
}
Snake::~Snake() {
	// TODO Auto-generated destructor stub
}
void Snake::tick(){
	if(cont++<Controller::getVel()){
		return;
	}
	cont =0;
	osMutexWait(*mutex, 100);
	for(int i=snk.size()-1;i>0;i--){

		snk[i].px=(int)snk[i-1].px;
		snk[i].py=(int)snk[i-1].py;
	}
	osMutexRelease(*mutex);
	int curr = Controller::getDir();
//	Display::LCD_Write_String(6,1,to_string(curr));
	if(curr!=-1&&((curr+2)%4)!=currDir){
		currDir = curr;
	}
	dx = dir[currDir].px;
	dy = dir[currDir].py;
	osMutexWait(*mutex, 100);
	snk[0].px = nextX();
	snk[0].py = nextY();
	if(autoBite()) resetGame();
	eatFood();
	osMutexRelease(*mutex);
}
void Snake::render(){
	osMutexWait(*mutex, 100);
	for(int i=0;i<snk.size();i++){
		snk[i].render();
	}
	osMutexRelease(*mutex);
}
float Snake::next(float cur,float dc,int max){
	cur+=dc;
	if(cur<0) cur= max-1;
	if(cur>=max) cur= 0;
	return cur;
}
void Snake::resetGame(){
	this->snk=Snake().snk;
	this->currDir =1;
	Display::LCD_Write_String(6, 2, "fim de jogo");
}
bool Snake::autoBite(){
	for(int i =1;i<snk.size();i++){
		if(snk[0].colidin(&snk[i])) return true;
	}
	return false;
}
void Snake::eatFood(){
	if(snk[0].colidin(food)){
		snk.push_back(node());
		food->eated= true;
	}

}
