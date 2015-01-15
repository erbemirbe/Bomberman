#include "stdafx.h"
#include "Bomb.h"

#include "Collider.h"
#include "Sprite.h"
#include "EntityManager.h"
#include "Steve.h"
#include "FireRoot.h"

#include <iostream>

Bomb::Bomb(Sprite* sprite, EntityManager* entityManager, int x, int y)
{
	m_sprite = sprite;
	m_entity_manager = entityManager;
	m_time = 3.f;
	m_x = x*64;
	m_y = y*64;
	m_blast_range = 5;
}

Bomb::~Bomb()
{
}

void Bomb::Reset(int x, int y)
{
	std::cout << "begining to reset?" << std::endl;
	m_x = x * 64;
	m_y = y * 64;
	Reset();
}

void Bomb::Reset()
{
	std::cout << "finishing reset" << std::endl;
	m_time = 3.f;

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
	m_x = x * 64;
	m_y = y * 64;
	m_collider->Refresh();
}

Collider* Bomb::GetCollider()
{
	return m_collider;
}

void Bomb::Update(float deltatime)
{
		m_time -= deltatime;
		if (m_time < 0) Explode();
}

void Bomb::Explode()
{
	//explode animation and stuff and then
	//create fire root with the fire amount
	FireRoot* fire = (FireRoot*)m_entity_manager->MakeEntity(ENTITY_FIRE_ROOT, m_x, m_y);
	fire->SetBlastRange(m_blast_range);
	//m_visible = false;
	Deactivate();
	m_entity_manager->RecycleEntity(this);
	std::cout << "boom" << std::endl;
	m_owner->ReturnBomb();
}

Sprite* Bomb::GetSprite()
{
	return m_sprite;
}

void Bomb::SetOwner(Steve* owner)
{
	m_owner = owner;
}