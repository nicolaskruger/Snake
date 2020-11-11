/*
 * Controller.h
 *
 *  Created on: Nov 10, 2020
 *      Author: nicolas-kruger
 */
#include "main.h"
#include "Display.h"
#include "Game.h"
#include "cmsis_os.h"
#include <vector>
extern ADC_HandleTypeDef hadc1;
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

class Controller {
private:
	static osMutexId* mutex;
	static bool up;
	static bool down;
	static bool left;
	static bool rigth;
	static int vel;
	static vector<bool*> val;
	static int32_t adRead(ADC_HandleTypeDef* hadc);
	Controller();
	static bool getSafe(bool (*f)()){
		bool b;
		osMutexWait(*mutex, 1000);
		b= f();
		osMutexRelease(*mutex);
	}
	static bool Up(){return up;}
	static bool Down(){return down;}
	static bool Left(){return left;}
	static bool Rigth(){return rigth;}

public:
	static void setMux(osMutexId* m){
		mutex = m;
	}
	static void atlVal();
	static bool getUp(){return getSafe(Up);}
	static bool getDown(){return getSafe(Down);}
	static bool getLeft(){return getSafe(Left);}
	static bool getRigth(){return getSafe(Rigth);}
	static int getDir();
	static double getVel(){
		osMutexWait(*mutex, 1000);
		double v = (double)vel*Game::fps()/2/4000;
		osMutexRelease(*mutex);
		return v;
	}
	static void Display();
	virtual ~Controller();
};

#endif /* CONTROLLER_H_ */
