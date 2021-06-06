#include "Map.h"
#include "constants.h"
#include <iostream>


//print funciton a pointer to the map array to get printed out
	void Map::printMap()
	{
		//while loop for the x axis of the array
		for (int y = 0; y < arraySize; ++y)
		{
			for (int x = 0; x < arraySize; ++x)
			{
				std::cout << Map::mapGeneration[y][x];
				if (x == 9)
				{
					std::cout << '\n';
				}
			}


		}
	}

	//this group of function goes through map, determines the amount of neighbors for reach cell and generates a new array for the next generation based on the below rules.
	//rules of the game are applied here:
	/*•	Any live cell with fewer than two live neighbors dies, as if by underpopulation 
	  •	Any live cell with two or three neighbors lives on the next generation. 
	  •	Any live cell with more than three live neighbors dies, as if by overpopulation. 
	  •	Any dead cell with exactly three live neighbors becomes a live cell as if by reproduction. 
*/
	void Map::traverseMap()
	{
		int numberOfNeighbors = 0;
		for (int y = 0; y < arraySize; ++y)
		{
			for (int x = 0; x < arraySize; ++x)
			{
				

				numberOfNeighbors = determineNeighbors(x, y);
				createNextGeneration(numberOfNeighbors, x, y);
				numberOfNeighbors = 0;
				

			}
			

		}
		swapMaps();

	}
	// determines the neightbors of each cell
	int Map::determineNeighbors(int x, int y)
	{
		int numberOfNeighbors{};
		for (int l = -1; l <= 1; ++l)
		{
			for (int i = -1; i <= 1; ++i)
			{
				if (l==0 && i==0)
				{
					continue;
				}
				else if (Map::mapGeneration[y + l][x + i] == 1)
				{
					++numberOfNeighbors;
				}
				
					



			}

		}
		return numberOfNeighbors;

	}
	//creates the next generation 
	void Map::createNextGeneration(int numberOfNeighbors, int x, int y)
	{
		if (numberOfNeighbors <= 2)
		{
			mapGenerationNext[y][x] = 0;
		}
		else if (mapGeneration[y][x] == 1 && numberOfNeighbors >= 2 && numberOfNeighbors <= 3)
		{
			mapGenerationNext[y][x] = 1;
		}
		else if (numberOfNeighbors > 3)
		{
			mapGenerationNext[y][x] = 0;
		}
		else if (numberOfNeighbors = 3 && mapGeneration[y][x] == 0)
		{
			mapGenerationNext[y][x] = 1;
		}

	}
	void Map::swapMaps()
	{
		for (int y{ 0 }; y < arraySize; ++y)
		{
			for (int x{ 0 }; x < arraySize; ++x)
			{
				Map::mapGeneration[y][x] = Map::mapGenerationNext[y][x];
				
			}
		}
	}


	