// ConwaysGameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "map.h"
#include "constants.h"
#include "Map.h"

int main()
{
	Map map{};
	while (true)
	{
		map.printMap();
		map.traverseMap();
		std::cout << '\n';
		map.printMap();
		std::cout << '\n';
	}

	map.printMap();
	map.traverseMap();
	std::cout << '\n';
	map.printMap();



}

