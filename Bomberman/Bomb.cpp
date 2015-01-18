#include "stdafx.h"
#include "Bomb.h"

#include "Collider.h"
#include "Sprite.h"
#include "EntityManager.h"
#include "map.h"
#include "Steve.h"
#include "FireRoot.h"

#include <iostream>

Bomb::Bomb(Sprite* sprite, EntityManager* entityManager, Map* map, int x, int y)
{
	m_sprite = sprite;
	m_entity_manager = entityManager;
	m_map = map;
	
	m_x = x*64;
	m_y = y*64;

	
	Reset();
}

void Bomb::Reset()
{
	if (m_map->GetPos(m_x / 64, m_y / 64) == BLOCK_FIRE)
	{
		Explode();
	}
	m_map->SetPos(m_x / 64, m_y / 64, BLOCK_BOMB);
	m_time = 3.f;
	m_blast_range = 1;
}

Bomb::~Bomb()
{
}

void Bomb::Reset(int x, int y)
{
	m_x = x * 64;
	m_y = y * 64;
	Reset();
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
	if (m_map->GetPos(m_x / 64, m_y / 64) == BLOCK_FIRE)
	{
		Explode();
	}
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
	if (m_owner)
		m_owner->ReturnBomb();
}

Sprite* Bomb::GetSprite()
{
	return m_sprite;
}

void Bomb::SetOwner(Steve* owner)
{
	m_owner = owner;
	m_blast_range = m_owner->GetBlastRange();
}