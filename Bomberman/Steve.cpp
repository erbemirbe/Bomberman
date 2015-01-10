// Steve.cpp

#include "stdafx.h"
#include "Keyboard.h"
#include "Sprite.h"
#include "Collider.h"
#include "Steve.h"
#include <iostream>


Steve::Steve(Keyboard* keyboard, Sprite* sprite, int x, int y)
{
	m_keyboard = keyboard;
	m_sprite = sprite;

	m_collider = new Collider(0, 0);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w, 
		m_sprite->GetRegion()->h);

	m_x = x;
	m_y = y;

	m_speed = 2.0f;

	m_bombs = 0;
	m_max_bombs = 3;
	
	Reset();
}

Steve::~Steve()
{
	if (m_collider)
		delete m_collider;
}

void Steve::Update(float deltatime)
{	
	if (m_keyboard->IsKeyDown(SDLK_w))
	{
		m_y--;
	}
	if (m_keyboard->IsKeyDown(SDLK_s))
	{
		m_y++;
	}
	if (m_keyboard->IsKeyDown(SDLK_a))
	{
		m_x--;
	}
	if (m_keyboard->IsKeyDown(SDLK_d))
	{
		m_x++;
	}
	if (m_keyboard->IsKeyDown(SDLK_v))
	{
		LayBomb();
	}
}
void Steve::LayBomb()
{
	if (m_bombs < m_max_bombs)
	{
		m_y++;
	}
}

Sprite* Steve::GetSprite()
{
	return m_sprite;
}

Collider* Steve::GetCollider()
{
	return m_collider;
}

float Steve::GetX()
{
	return m_x;
}

float Steve::GetY()
{
	return m_y;
}

void Steve::Reset()
{
	m_collider->SetPosition(m_x, m_y);
}

bool Steve::IsVisible() 
{
	return true;
}

EEntityType Steve::GetType()
{
	return ENTITY_STEVE;
}
