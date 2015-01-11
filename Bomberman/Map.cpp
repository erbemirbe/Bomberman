//map.cpp

#include "stdafx.h"
#include "Map.h"

#include <iostream>

Map::Map(int* intMap, int width, int height)
{
	m_int_map = intMap;
	m_width = width;
	m_height = height;
}

Map::~Map()
{
	delete[] m_int_map;
}

int Map::GetWidth()
{
	return m_width;
}

int Map::GetHeight()
{
	return m_height;
}

int Map::Size()
{
	return m_width * m_height;
}
int* Map::GetIntMap()
{
	return m_int_map;
}

void Map::Print()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			std::cout << m_int_map[y * m_width + x];
		}
		std::cout << std::endl;
	}
}
