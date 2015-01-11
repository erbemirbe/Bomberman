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

void Bomb::Reset()
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

void Bomb::Update(float deltatime)
{
	/*
	if (IsActive)
	{
		m_time -= deltatime;
		if (m_time < 0)
			Explode();
		//return true;
	}
	else {
		//return false;
	}
	*/
}

void Bomb::Explode()
{
	//explode animation and stuff and then
	Deactivate();
}

Sprite* Bomb::GetSprite()
{
	return m_sprite;
}