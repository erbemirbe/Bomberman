//Wall.cpp
#include "stdafx.h"
#include "Wall.h"

#include "Collider.h"
#include "Sprite.h"

Wall::Wall(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_x = x;
	m_y = y;
}

Wall::~Wall()
{

}

void Wall::Reset()
{

}

bool Wall::IsVisible()
{
	return true;
}

EEntityType Wall::GetType()
{
	return ENTITY_WALL;
}

Collider* Wall::GetCollider()
{
	return m_collider;
}

void Wall::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_collider->Refresh();
}

void Wall::Update(float deltatime)
{

}

Sprite* Wall::GetSprite()
{
	return m_sprite;
}