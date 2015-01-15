//EntityManager.cpp

#include "stdafx.h"
#include "EntityManager.h"

#include "SpriteManager.h"
#include "InputManager.h"
#include "Map.h"

#include "Bomb.h"
#include "Steve.h"
#include "Block.h"
#include "Ball.h"
#include "Wall.h"
#include "Fire.h"
#include "FireRoot.h"
#include "Grass.h"

#include <vector>
#include <iostream>

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

Entity* EntityManager::MakeEntity(int EntityType, int x, int y)
{
	std::cout << "creating something" << std::endl;
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
			filename = "../assets/bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 128, 0, 64, 64);
			entity = new Bomb(sprite, this, x, y);
		break;

		case ENTITY_STEVE:
			filename = "../assets/bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 64, 64, 64, 64);
			entity = new Steve(m_input_manager->GetKeyboard(), this, m_map, sprite, x, y);
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
		case ENTITY_FIRE_ROOT:
			filename = "../assets/Bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 64, 320, 64, 64);
			entity = new FireRoot(sprite, m_map, this, x, y);
		break;
		case ENTITY_FIRE:
			filename = "../assets/Bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 128, 320, 64, 64);
			entity = new Fire(sprite, m_map, this, x, y);
		break;
		case ENTITY_GRASS:
			filename = "../assets/Bomberman.png";
			sprite = m_sprite_manager->CreateSprite(filename, 0, 64, 64, 64);
			entity = new Grass(sprite, x, y);
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
		entity = it->second->back();

		entity->Reset(x,y);

		//remove from inactive
		it->second->pop_back();

		//after activating entity check if entity list is empty and delete it if it is
		if (it->second->size() == 0){
			delete it->second;
			m_inactive_entities.erase(it);
		}
	}
	m_active_entities.push_back(entity);
	return entity;
}

void EntityManager::RecycleEntity(Entity* entity)
{
	for (unsigned int i = 0; i < m_active_entities.size(); i++)
	{
		if (m_active_entities[i] == entity){
			auto it = m_inactive_entities.find(entity->GetType());

			if (it == m_inactive_entities.end())
			{ //  There is no inactive entities map for the specified type of entity
				m_inactive_entities.insert(
					std::pair<int, std::vector<Entity*>*> (
						entity->GetType(),
						new std::vector<Entity*>
					)
				);
				it = m_inactive_entities.find(entity->GetType());
			}

			it->second->push_back(entity);
			m_active_entities.erase(m_active_entities.begin() + i);
			break;
		}
	}
}

/*
for types
if entity.enum == enum
	store in enum
end for
if no found enum create new enum

*/