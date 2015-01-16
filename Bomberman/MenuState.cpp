//MenuState.cpp
#include "stdafx.h"
#include "MenuState.h"
#include "Sprite.h"
#include "SpriteText.h"
#include "SpriteManager.h"
#include "GameState.h"
#include "DrawManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "MusicClip.h"
#include "Mouse.h"
#include "Button.h"
#include <iostream>
MenuState::MenuState(System& system)
{
	m_system = system;
	m_active = true;
	m_mouse = m_system.input_manager->GetMouse();
	m_background = m_system.sprite_manager->CreateSprite("../assets/mainmenue.png", 0, 0, 1280, 960);
	
	m_buttons.push_back(new Button(m_system.sprite_manager->CreateSprite("../assets/start.png", 0, 0, 240, 119), 600, 400, 240, 119));
	m_buttons.push_back(new Button(m_system.sprite_manager->CreateSprite("../assets/quit.png", 0, 0, 240, 119), 600, 600, 240, 119));
	
	m_background_music = m_system.sound_manager->CreateMusicClip("../assets/leveltheme.mid");
	m_background_music->Play();
}

MenuState::~MenuState()
{
	m_background_music->Stop();
	delete m_background_music;
}

bool MenuState::Update(float deltatime)
{
	if (!m_active)
		return false;
	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		if (m_mouse->GetX() > m_buttons[i]->GetX()
		&& m_mouse->GetX() <  m_buttons[i]->GetX() + m_buttons[i]->GetWidth()
		&& m_mouse->GetY() > m_buttons[i]->GetY()
		&& m_mouse->GetY() < m_buttons[i]->GetY() + m_buttons[i]->GetHeight()
			){
			if (m_mouse->IsButtonDown(0)){
				
				switch (i)
				{
				case 0:
					m_next_state = new GameState(m_system);
					break;
				case 1:
					break;
				}
				return false;
				break;
			}

		}
	}
	return true;
}

void MenuState::Draw()
{
	m_system.draw_manager->Draw(m_background, 0, 0);
	for (unsigned int i = 0; i < m_buttons.size();i++)
	{
		m_system.draw_manager->Draw(m_buttons[i]->GetSprite(), m_buttons[i]->GetX(), m_buttons[i]->GetY());
	}
}

State* MenuState::NextState(){
	return m_next_state;
}