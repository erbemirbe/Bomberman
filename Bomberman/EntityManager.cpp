//EntityManager.cpp

#include "stdafx.h"
#include "EntityManager.h"

#include "Entity.h"
#include "EntityComponent.h"

#include "CTile.h"
#include "CPos2D.h"
#include "Sprite.h"
#include "SpriteManager.h"

//#include <fstream>

EntityManager::EntityManager(SpriteManager* SprtMan)
{
	m_sprite_manager = SprtMan;
	/*dofix
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
	//dofix
	Entity* shizzle = nullptr;
	return shizzle;
}

Entity* EntityManager::CreatePlayerEntity(int XTile, int YTile)
{

	Entity* bomb = new Entity();

	EntityComponent* tile = new Ctile(XTile, YTile);
	bomb->AddComponent("tile", tile);

	//EntityComponent* timer = new CTimer(0, 0);
	//bomb->AddComponent("Timer", timer);

	EntityComponent* position = new CPos2D(0, 0);
	bomb->AddComponent("position", position);

	//EntityComponent* sprite m_sprite_manager->createsprite("../assets/ss_bomberman_minimalistic.png", 0, 0, 80, 16);
	//bomb->AddComponent("sprite", sprite);

	m_entities.push_back(bomb);

	return bomb;

}

void EntityManager::DeleteEntity(std::string a)
{
	//delete entity
}