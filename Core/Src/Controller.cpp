/*
 * Controller.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: nicolas-kruger
 */

#include "Controller.h"
bool Controller::up = false;
bool Controller::down = false;
bool Controller::left = false;
bool Controller::rigth = false;
int Controller::vel = 0;
osMutexId* Controller::mutex = NULL;
vector<bool*> Controller::val = {
		&Controller::up,
		&Controller::rigth,
		&Controller::down,
		&Controller::left,
};
Controller::Controller() {
	// TODO Auto-generated constructor stub

}

Controller::~Controller() {
	// TODO Auto-generated destructor stub
}

void Controller::atlVal(){
	osMutexWait(*mutex, 1000);
	left = HAL_GPIO_ReadPin(LEFT_GPIO_Port, LEFT_Pin);
	rigth = HAL_GPIO_ReadPin(RIGTH_GPIO_Port,RIGTH_Pin);
	up = HAL_GPIO_ReadPin(UP_GPIO_Port,UP_Pin);
	down = HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin);
	vel = adRead(&hadc1);
	osMutexRelease(*mutex);
}
void Controller::Display(){
	Display::LCD_Write_String(0, 0,to_string(getLeft()));
	Display::LCD_Write_String(0, 1,to_string(getRigth()));
	Display::LCD_Write_String(0, 2,to_string(getUp()));
	Display::LCD_Write_String(0, 3,to_string(getDown()));
	Display::LCD_Write_String(0, 4, to_string(vel));
}
int32_t Controller::adRead(ADC_HandleTypeDef* hadc){
	HAL_ADC_Start(hadc);
	while(HAL_ADC_PollForConversion(hadc, 5)!= HAL_OK){}
	return HAL_ADC_GetValue(hadc);
}
int Controller::getDir(){
	for(int i =0;i<val.size();i++){
		bool b;
		osMutexWait(*mutex, 1000);
		b=val[i][0];
		osMutexRelease(*mutex);
		if(!b) return i;
	}
	return -1;
}
