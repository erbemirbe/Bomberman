//Entity.cpp
#include "stdafx.h"
#include "Entity.h"
#include "EntityComponent.h"
#include "string"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::AddComponent(std::string string, EntityComponent* component)
{
	m_components.insert(std::pair < std::string, EntityComponent* > ( string, component ));
}

void Entity::RemoveComponent(std::string string)
{
	m_components.find(string);
	//the above . detach
	//I need to know how to handle maps so that I can do this...
}
