//EntityManager.h

#pragma once

#include <String>
#include <vector>

class Entity;

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	Entity* CreateEntity(std::string a);

	Entity* CreatePlayerEntity(int, int); // for testing, will be moved or removed

	void DeleteEntity(std::string a);

private:
	std::vector<Entity*>  m_entities;
};