#include "stdafx.h"
#include "Bomb.h"
#include "Collider.h"
#include "Sprite.h"

Bomb::Bomb(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_x = x;
	m_y = y;
}

Bomb::~Bomb()
{
}

void Reset()
{

}

bool Bomb::IsVisible()
{
	return true;
}

EEntityType Bomb::GetType()
{
	return ENTITY_BOMB;
}

void Bomb::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_collider->Refresh();
}

Collider* Bomb::GetCollider()
{
	return m_collider;
}

void Bomb::Activate()
{
	m_active = true;
}

bool Bomb::IsActive()
{
	return m_active;
}

void Bomb::Update(float deltatime)
{

}
Sprite* Bomb::GetSprite()
{
	return m_sprite;
}
float Bomb::GetX()
{
	return m_x;
}
float Bomb::GetY()
{
	return m_y;
}