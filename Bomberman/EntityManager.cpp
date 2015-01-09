//EntityManager.cpp

#include "stdafx.h"
#include "EntityManager.h"

#include <vector>

#include "SpriteManager.h"
#include "InputManager.h"


#include "Bomb.h"
#include "Steve.h"
#include "Block.h"
#include "Ball.h"

EntityManager::EntityManager(SpriteManager* spriteManager, InputManager* inputManager)
{
	m_sprite_manager = spriteManager;
	m_input_manager = inputManager;
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
	auto it = m_inactive_entities.find(EntityType);
	if (it == m_inactive_entities.end())
	{
		//if no inactive entities of the type exists
		if (EntityType == ENTITY_BOMB){
			std::string filename = "../assets/ss_bomberman_minimalistic.png";
			Sprite* sprite = m_sprite_manager->CreateSprite(filename, 16, 16, 64, 64);
			Bomb* bomb = new Bomb(
				sprite,
				x,
				y
			);
			m_active_entities.push_back(bomb);
		}
		else if (EntityType == ENTITY_STEVE){
			std::string filename = "../assets/ss_bomberman_minimalistic.png";
			Sprite* sprite = m_sprite_manager->CreateSprite(filename, 32, 32, 64, 64);
			Steve* steve = new Steve(
				m_input_manager->GetKeyboard(),
				sprite,
				x,
				y
			);
			m_active_entities.push_back(steve);
		}
		else if (EntityType == ENTITY_BRICK_WALL){
		}
		else if (EntityType == ENTITY_WALL){
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
		m_active_entities.push_back(it->second.back());


		//remove from inactive
		it->second.pop_back();

		//after activating entity check if entity list is empty and delete it if it is
		if (it->second.size() == 0)
			m_inactive_entities.erase(it);
	}
}

/*
for types
if entity.enum == enum
	store in enum
end for
if no found enum create new enum

*/