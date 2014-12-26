//EntityCreator.h

#pragma once

#include <String>

class Entity;

class EntityCreator
{
public:
	EntityCreator();
	~EntityCreator();

	Entity* Create(std::string a);

private:

};