//Entity.cpp
#include "stdafx.h"
#include "Entity.h"
#include "EntityManager.h"

Entity::Entity()
{
	m_active = true;
}

float Entity::GetX()
{
	return m_x;
}

float Entity::GetY()
{
	return m_y;
}

void Entity::Activate()
{
	m_active = true;
}
void Entity::Deactivate()
{
	m_active = false;
}

bool Entity::IsActive()
{
	return m_active;
}
void Entity::Reset(int x, int y)
{
	m_x = x;
	m_y = y;
	Reset();
}