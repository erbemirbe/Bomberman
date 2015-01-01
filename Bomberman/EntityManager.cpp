//EntityManager.cpp

#include <fstream>

#include "stdafx.h"
#include "EntityManager.h"
#include "Entity.h"



EntityManager::EntityManager()
{
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
	/*
		load in file that contains paths to files explaining the enemies
		for loop
			load in these file paths
			save their names
	*/
}

EntityManager::~EntityManager()
{
	//dofix
	//delete all entities
}

Entity* EntityManager::CreateEntity(std::string a)
{
	Entity shizzle;
	return &shizzle;
}

Entity* EntityManager::DeleteEntity(std::string a)
{
	Entity shizzle;
	return &shizzle;
}