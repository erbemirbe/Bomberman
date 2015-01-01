//EntityManager.h

#pragma once

#include <String>

class Entity;

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	Entity* CreateEntity(std::string a);
	void DeleteEntity(std::string a);

private:

};