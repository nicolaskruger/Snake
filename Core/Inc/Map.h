/*
 * Map.h
 *
 *  Created on: Nov 9, 2020
 *      Author: nicolas-kruger
 */

#ifndef MAP_H_
#define MAP_H_

class Map {
protected:
	Map();
public:
	static int gridX(){return 6;}
	static int gridY(){return 1;}
	static int maxX(){return 14;}
	static int maxY(){return 6;}
	virtual ~Map();
};

#endif /* MAP_H_ */
