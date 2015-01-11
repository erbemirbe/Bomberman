#include "stdafx.h"
#include "Fire.h"
#include "Collider.h"
#include "Sprite.h"

Fire::Fire(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_x = x;
	m_y = y;
}

Fire::~Fire()
{

}

void Fire::Reset()
{
	
}

bool Fire::IsVisible()
{
	return true;
}

EEntityType Fire::GetType()
{
	return ENTITY_FIRE;
}

Collider* Fire::GetCollider()
{
	return m_collider;
}

void Fire::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_collider->Refresh();
}

void Fire::Update(float deltatime)
{

}

Sprite* Fire::GetSprite()
{
	return m_sprite;
}