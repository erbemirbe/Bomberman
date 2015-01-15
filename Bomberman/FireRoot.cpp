//FireRootRoot.cpp
#include "stdafx.h"
#include "FireRoot.h"


#include "Collider.h"
#include "Sprite.h"
#include "map.h"
#include "EntityManager.h"

#include "Fire.h"

#include <iostream>

FireRoot::FireRoot(Sprite* sprite, Map* map, EntityManager* entityManager, int x, int y)
{
	m_sprite = sprite;
	m_map = map;
	m_entity_manager = entityManager;

	m_x = x;
	m_y = y;
	m_time = 0.5f;
}

void FireRoot::SetBlastRange(int blastRange){
	std::cout << "what is blast range? " << blastRange << std::endl;
	m_blast_range = blastRange;
	Init();
}

void FireRoot::Init()
{
	std::cout << "INIT" << std::endl;
	int gridX = m_x / 64;
	int gridY = m_y / 64;

	m_map->SetPos(gridX, gridY, 3);


	if (m_blast_range <= 0)
		return;

	Blast(gridX - 1, gridY, FIRE_LEFT);
	Blast(gridX + 1, gridY, FIRE_RIGHT);
	Blast(gridX, gridY - 1, FIRE_UP);
	Blast(gridX, gridY + 1, FIRE_DOWN);
	std::cout << "WTF?" << std::endl;
}

void FireRoot::Blast(int xGrid, int yGrid, int dir)
{
	std::cout << "Fire Root is blasting" << dir << std::endl;
	if (xGrid < 0 || yGrid < 0
		|| xGrid > m_map->GetWidth()
		|| yGrid > m_map->GetHeight()
	) return;
	

	switch (m_map->GetPos(xGrid, yGrid))
	{
		case BLOCK_GRASS:
		{
			Fire* fire = (Fire*)m_entity_manager->MakeEntity(ENTITY_FIRE, xGrid*64, yGrid*64);
			fire->SetBlastRangeAndDirection(m_blast_range - 1, dir);
			break;
		}

		case BLOCK_BRICK:
		{
			Fire* fire = (Fire*)m_entity_manager->MakeEntity(ENTITY_FIRE, xGrid*64, yGrid*64);
			fire->SetBlastRangeAndDirection(0, dir);
			break;
		}
	}
}

FireRoot::~FireRoot()
{

}

void FireRoot::Reset()
{
	m_time = 0.5f;
}

bool FireRoot::IsVisible()
{
	return true;
}

EEntityType FireRoot::GetType()
{
	return ENTITY_FIRE_ROOT;
}

Collider* FireRoot::GetCollider()
{
	return m_collider;
}

void FireRoot::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_collider->Refresh();
}

void FireRoot::Update(float deltatime)
{
	m_time -= deltatime;
	if (m_time < 0){
		m_map->SetPos(m_x / 64, m_y / 64, 1);
		m_entity_manager->RecycleEntity(this);
	}
}

Sprite* FireRoot::GetSprite()
{
	return m_sprite;
}