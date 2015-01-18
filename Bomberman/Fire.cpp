#include "stdafx.h"
#include "Fire.h"
#include "map.h"
#include "Collider.h"
#include "Sprite.h"
#include "EntityManager.h"
#include <iostream>
Fire::Fire(Sprite* sprite, Map* map, EntityManager* entityManager, int x, int y)
{
	m_sprite = sprite;
	m_map = map;
	m_entity_manager = entityManager;
	m_x = x;
	m_y = y;
	Reset();
}

void Fire::Reset()
{
	m_time = .5f;

	if (m_map->GetPos(m_x/64,m_y/64) == BLOCK_BRICK)
		m_power_up = true;
	else
		m_power_up = false;
	
	m_map->SetPos(m_x / 64, m_y / 64, BLOCK_FIRE);
}


Fire::~Fire()
{

}

void Fire::SetBlastRangeAndDirection(int blastRange, int fireDir){

	if (blastRange <= 0)
		return;

	m_blast_range = blastRange;
	switch (fireDir)
	{
	case FIRE_UP:		Blast(m_x / 64, m_y / 64 - 1, fireDir); break;
	case FIRE_RIGHT:	Blast(m_x / 64 + 1, m_y / 64, fireDir); break;
	case FIRE_LEFT:		Blast(m_x / 64 - 1, m_y / 64, fireDir); break;
	case FIRE_DOWN:		Blast(m_x / 64, m_y / 64 + 1, fireDir); break;
	}
	

}

void Fire::Blast(int xGrid, int yGrid, int dir)
{
	if (xGrid < 0 || yGrid < 0
		|| xGrid > m_map->GetWidth()
		|| yGrid > m_map->GetHeight()
		) return;


	switch (m_map->GetPos(xGrid, yGrid))
	{
		case BLOCK_GRASS:
		case BLOCK_BOMB:
		case BLOCK_PWRUP_BOMB:
		case BLOCK_PWRUP_FIRE:
		case BLOCK_PWRUP_SPEED:
		{
			Fire* fire = (Fire*)m_entity_manager->MakeEntity(ENTITY_FIRE, xGrid * 64, yGrid * 64);
			fire->SetBlastRangeAndDirection(m_blast_range - 1, dir);
			break;
		}
		case BLOCK_BRICK:
		{
			Fire* fire = (Fire*)m_entity_manager->MakeEntity(ENTITY_FIRE, xGrid * 64, yGrid * 64);
			fire->SetBlastRangeAndDirection(0, dir);
			break;
		}
	}
}

void Fire::PowerUp()
{
	m_power_up = true;
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
	m_time -= deltatime;
	if (m_time < 0)
	{
		if (m_power_up)
		{
			if (rand() % 5 == 1)
			{
				switch (rand() % 3)
				{
					case 0: m_map->SetPos(m_x / 64, m_y / 64, BLOCK_PWRUP_FIRE);	break;
					case 1: m_map->SetPos(m_x / 64, m_y / 64, BLOCK_PWRUP_SPEED);	break;
					case 2: m_map->SetPos(m_x / 64, m_y / 64, BLOCK_PWRUP_BOMB);	break;
				}
			}
			else m_map->SetPos(m_x / 64, m_y / 64, BLOCK_GRASS);
		}
		else m_map->SetPos(m_x / 64, m_y / 64, BLOCK_GRASS);

		m_entity_manager->RecycleEntity(this);
	}
}

Sprite* Fire::GetSprite()
{
	return m_sprite;
}