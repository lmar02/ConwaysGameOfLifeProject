#ifndef MAP_H
#define MAP_H

#include "constants.h"
#include <stdlib.h>  


class Map
{

private:

	int mapGeneration[arraySize][arraySize];

	int mapGenerationNext[arraySize][arraySize];

public:

	//generate initial map
	void generateStartingGeneraiton();
	//print funciton a pointer to the map array to get printed out. Defined in Map.cpp
	void printMap();
	//this function goes through map and generates a new array for the next generation Defined in Map.cpp
	void traverseMap();
	//determine how many neightbors their are near the cell
	int determineNeighbors(int x, int y);
	//generates the next generation of the cells
	void createNextGeneration(int numberOfneighbors, int x, int y);
	//takes the newly created map/generation and moves it on the old generation.
	void swapMaps();

};

#endif