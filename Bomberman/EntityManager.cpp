//EntityManager.cpp

#include "stdafx.h"
#include "EntityManager.h"

#include <vector>

#include "SpriteManager.h"
#include "InputManager.h"
#include "Map.h"

#include "Bomb.h"
#include "Steve.h"
#include "Block.h"
#include "Ball.h"
#include "Wall.h"

EntityManager::EntityManager(SpriteManager* spriteManager, InputManager* inputManager, Map* map)
{
	m_sprite_manager = spriteManager;
	m_input_manager = inputManager;
	m_map = map;
}

EntityManager::~EntityManager()
{

}

std::vector<Entity*>* EntityManager::GetActiveEntities()
{
	return &m_active_entities;
}

void EntityManager::MakeEntity(int EntityType, int x, int y)
{
	Entity* entity;
	auto it = m_inactive_entities.find(EntityType);
	if (it == m_inactive_entities.end())
	{
		//if no inactive entities of the type exists
		std::string filename;
		switch(EntityType)
		{
			Sprite* sprite;
		case ENTITY_BOMB:
			filename = "../assets/ss_bomberman_minimalistic.png";
			sprite = m_sprite_manager->CreateSprite(filename, 16, 16, 64, 64);
			entity = new Bomb(sprite, x, y);
		break;

		case ENTITY_STEVE:
			filename = "../assets/ss_bomberman_minimalistic.png";
			sprite = m_sprite_manager->CreateSprite(filename, 00, 00, 64, 64);
			entity = new Steve(m_input_manager->GetKeyboard(), m_map, sprite, x, y);
		break;

		case ENTITY_BRICK:
			filename = "../assets/Bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 64, 0, 64, 64);
			entity = new Wall(sprite, x, y);
		break;

		case ENTITY_WALL:
			filename = "../assets/Bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 0, 0, 64, 64);
			entity = new Wall(sprite, x, y);
		break;

		}
	}
	else
	{
		//if there are inactive entities
		//activate an entity instead

		//get specific entity of that type from inactive
		//reset entity
		//it->second.back()->Reset();

		//add to active
		entity = it->second.back();

		//remove from inactive
		it->second.pop_back();

		//after activating entity check if entity list is empty and delete it if it is
		if (it->second.size() == 0)
			m_inactive_entities.erase(it);
	}
	m_active_entities.push_back(entity);
}

void EntityManager::RecycleEntity()
{

}

/*
for types
if entity.enum == enum
	store in enum
end for
if no found enum create new enum

*/