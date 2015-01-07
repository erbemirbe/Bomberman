//EntityManager.h

#pragma once

#include <String>
#include <vector>

class Entity;
class SpriteManager;

class EntityManager
{
public:
	EntityManager(SpriteManager* sprtMan);
	~EntityManager();

	Entity* CreateEntity(std::string a);
	Entity* CreatePlayerEntity(int, int); // for testing, will be moved or removed
	void DeleteEntity(std::string a);

private:
	SpriteManager* m_sprite_manager;
	std::vector<Entity*>  m_entities;
};