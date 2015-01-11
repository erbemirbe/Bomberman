// MapGenerator.cpp
#include "stdafx.h"
#include "MapGenerator.h"
#include "Map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>

MapGenerator::MapGenerator()
{

}

Map* MapGenerator::LoadMap()
{
	std::ifstream stream;
	stream.open("CoolFile.txt");

	if (stream.is_open())
	{
		int width;
		int height;
		int* intMap;

		int i = 0;

		stream >> width;
		stream >> height;

		intMap = new int[width * height];

		while (!stream.eof())
		{
			stream >> intMap[i];
				i++;
		}
		return new Map(intMap, width, height);
	}
	stream.close();
}

Map* MapGenerator::Gen( int width, int height)
{

	width = 2 * width + 1;
	height = 2 * height + 1;
	int* intMap = new int[width * height];
	
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x % 2 == 1 && y % 2) intMap[y * width + x] = 0; 
			else intMap[y * width + x] = 1 + rand()%2;
		}
	}

	//empty left top corner
	intMap[0 * width + 0] = 1;
	intMap[1 * width + 0] = 1;
	intMap[0 * width + 1] = 1;

	return new Map(intMap, width, height);
}