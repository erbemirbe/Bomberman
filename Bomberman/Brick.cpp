#include "stdafx.h"
#include "Brick.h"
#include "Collider.h"
#include "Sprite.h"

Brick::Brick(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_x = x;
	m_y = y;
}

Brick::~Brick()
{

}

void Brick::Reset()
{

}

bool Brick::IsVisible()
{
	return true;
}

EEntityType Brick::GetType()
{
	return ENTITY_BRICK;
}

Collider* Brick::GetCollider()
{
	return m_collider;
}

void Brick::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_collider->Refresh();
}

void Brick::Update(float deltatime)
{

}

Sprite* Brick::GetSprite()
{
	return m_sprite;
}