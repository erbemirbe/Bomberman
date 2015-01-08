// Steve.cpp

#include "stdafx.h"
#include "Keyboard.h"
#include "Sprite.h"
#include "Collider.h"
#include "Steve.h"
#include <iostream>


Steve::Steve(Keyboard* keyboard, Sprite* sprite, int screen_width, int screen_height)
{
	m_keyboard = keyboard;
	m_sprite = sprite;

	m_collider = new Collider(0, 0);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w, 
		m_sprite->GetRegion()->h);

	m_x = 0.0f;
	m_y = 0.0f;
	m_screen_width = screen_width;
	m_screen_height = screen_height;

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
//	if ()
	//m_keyboard;
	/*float deltaX = m_mouse->GetX() - (m_x + static_cast<float>(m_sprite->GetRegion()->w * 0.5f));
	if (static_cast<int>(deltaX) != 0)
	{
		float dirX = deltaX / abs(deltaX);
		m_x += m_speed * abs(deltaX) * deltatime * dirX;

		if (m_x < 0.0f)
			m_x = 0.0f;
		else if (m_x > m_screen_width - 80.0f)
			m_x = m_screen_width - 80.0f;

		m_collider->SetPosition(m_x, m_y);
	}*/
	
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
	m_x = m_screen_width / 2 - 40;
	m_y = m_screen_height - 60 - 8;
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
