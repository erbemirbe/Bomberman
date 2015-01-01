// MapGenerator.cpp
#include "stdafx.h"
#include "MapGenerator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

MapGenerator::MapGenerator(const int width, const int height)
{
	m_width = 2 * width + 1;
	m_height = 2 * height + 1;

	m_map = new int[m_width * m_height];
	

	//m_map[0] = 1;
	//m_map[2] = 1;
	//m_map[23] = 1;
	//m_map = nullptr;
	Gen();
}

MapGenerator::~MapGenerator()
{
	delete[] m_map;
}

void MapGenerator::Print()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			std::cout << m_map[y * m_width + x];
		}

		std::cout << std::endl;
	}
}

void MapGenerator::LoadMap(){

	std::ifstream stream;
	stream.open("CoolFile.txt");

	if (stream.is_open())
	{
		int i = 0;

		stream >> m_width;
		stream >> m_height;

		while (!stream.eof())
		{
			stream >> m_map[i];
				i++;
		}
	}
	stream.close();

}

void MapGenerator::Gen()
{
	
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (x % 2 == 1 && y % 2) m_map[y * m_width + x] = 0; 
			else m_map[y * m_width + x] = 1 + rand()%2;
		}
	}
	m_map[0 * m_width + 0] = 1;
	m_map[1 * m_width + 0] = 1;
	m_map[0 * m_width + 1] = 1;
}