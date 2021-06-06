#ifndef MAP_H
#define MAP_H

#include "constants.h"


class Map
{

private:

	int mapGeneration[arraySize][arraySize]{ { 1,0,1,0,0,0,1,0,1,0 },
												{ 1,0,0,0,1,1,0,1,0,1 },
												{ 0,1,1,1,0,0,1,0,0,0 },
												{ 0,0,0,1,0,1,1,0,1,1 },
												{ 1,1,1,0,0,1,0,1,0,0 },
												{ 0,1,1,0,0,1,0,0,0,1 },
												{ 0,1,0,0,0,1,0,0,1,0 },
												{ 0,1,1,0,0,1,1,0,0,0 },
												{ 1,1,0,0,0,0,1,1,0,1 },
												{ 0,1,0,0,1,0,0,0,1,0 } };;

	int mapGenerationNext[arraySize][arraySize];

public:

	//print funciton a pointer to the map array to get printed out. Defined in Map.cpp
	void printMap();
	//this function goes through map and generates a new array for the next generation Defined in Map.cpp
	void traverseMap();
	//determine how many neightbors their are near the cell
	int determineNeighbors(int x, int y);
	//generates the next generation of the cells
	void CreateNextGeneration(int numberOfneighbors, int x, int y);

};

#endif