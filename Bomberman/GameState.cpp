// GameState.cpp

#include "stdafx.h"
#include "Mouse.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "SpriteManager.h"

#include "EntityManager.h"
#include "Sprite.h"
#include "GameState.h"

#include "Entity.h"

#include "Fire.h"

#include "Collider.h"
#include "CollisionManager.h"
#include "MapGenerator.h"
#include "Map.h"

#include "SoundManager.h"
#include "MusicClip.h"
#include "SoundClip.h"
GameState::GameState(System& system)
{
	m_systems = system;

	MapGenerator* mapGen = new MapGenerator();
	m_map = mapGen->LoadMap();

	SoundClip* Shitpointer = m_systems.sound_manager->CreateSoundClip("../assets/bomb.mp3");
	Shitpointer->Play();

	m_entity_manager = new EntityManager(m_systems.sprite_manager, m_systems.input_manager, m_map, m_systems.sound_manager);
	m_entities = m_entity_manager->GetActiveEntities();
	
	//Create map Entities'
	/*
	int* intMap = m_map->GetIntMap();
	for (int i = 0; i < m_map->Size(); i++)
	{
		switch (intMap[i])
		{

		case BLOCK_WALL:
			m_entity_manager->MakeEntity(
				ENTITY_WALL,
				64 * (i % m_map->GetWidth()),
				64 * (i / m_map->GetWidth())
				);
		break;

		case BLOCK_BRICK:
			m_entity_manager->MakeEntity(
				ENTITY_BRICK,
				64 * (i % m_map->GetWidth()),
				64 * (i / m_map->GetWidth())
			);
		break;
		
		}
	}
	*/
	m_entity_manager->MakeEntity(ENTITY_WALL, 0, 0);
	m_entity_manager->MakeEntity(ENTITY_GRASS, 0, 0);
	m_entity_manager->MakeEntity(ENTITY_BRICK, 0, 0);
	//m_entity_manager->MakeEntity(ENTITY_BOMB, 64, 0);
	m_entity_manager->MakeEntity(ENTITY_STEVE, 0, 0);
	

//	m_entity_manager->MakeEntity(ENTITY_FIRE, 120, 300);
	//m_entity_manager->MakeEntity(ENTITY_FIRE, 300, 100);

	//SpriteText* spritetext = m_systems.sprite_manager->CreateSprite("TTF", 50, "HelloWorld", 100, 100,100);


	m_active = false;

	m_background_music = m_systems.sound_manager->CreateMusicClip("../assets/multiplayer.mid");
	m_background_music->Play();
}

GameState::~GameState()
{
	delete m_background_music;

	int c = 0;
	auto it = m_entities->begin();
	while (it != m_entities->end())
	{
		Sprite* sprite = (*it)->GetSprite();
		if (sprite)
			m_systems.sprite_manager->DestroySprite(sprite);
		delete (*it);
		++it;
		c++;
	}
	m_entities->clear();
}

bool GameState::Update(float deltatime)
{
	// update all entities
	for (unsigned int i = 0; i < m_entities->size(); i++)
	{
		if (! (*m_entities)[i]->IsVisible())
			continue;

		/*
		if ( (*m_entities)[i]->GetType() == ENTITY_BOMB )
		{
			if (! (*m_entities)[i]->Update(deltatime) )
				//pop it
		}
		else
		{*/
			(*m_entities)[i]->Update(deltatime);
		//}

		/*
		// note(tommi): special treatment for the ball
		if (m_entities[i]->GetType() == ENTITY_BALL)
		{
			// note(tommi): we static_cast the ball from entity 
			//   to ball we know that it is a ball since 
			//   we check for entity type
			Ball* ball = static_cast<Ball*>(m_entities[i]);

			if (!ball->IsActive() && m_active)
			{
				// reset the game
				m_active = false;
			}
			else if (!ball->IsActive())
			{
				// here the ball follows the steve
				// note(tommi): we can do this because we always 
				//   add the steve first in the vector of entities
				Steve* steve = static_cast<Steve*>(m_entities[0]);

				float steveHalfWidth = steve->GetSprite()->GetRegion()->w * 0.5f;
				float steveHalfHeight = steve->GetSprite()->GetRegion()->h * 0.5f;

				float stevePosX = steve->GetX();
				float stevePosY = steve->GetY();

				float ballHalfWidth = ball->GetSprite()->GetRegion()->w	* 0.5f;
				float ballHalfHeight = ball->GetSprite()->GetRegion()->h	* 0.5f;

				float ballNewX = stevePosX + steveHalfWidth - ballHalfWidth;
				float ballNewY = stevePosY - steveHalfHeight - ballHalfHeight;

				ball->SetPosition(ballNewX, ballNewY);

				Mouse* mouse = m_systems.input_manager->GetMouse();
				if (mouse->IsButtonDown(0) && !m_active)
				{
					ball->Activate();
					m_active = true;
				}
			}
		}
		*/
	}

	// we always do collision checking after updating 
	// positions et al in entities
	CollisionChecking();
	
	return true;
}

void GameState::Draw()
{
	int* intMap = m_map->GetIntMap();

	for (int y = 0; y < m_map->GetHeight(); y++){
		for (int x = 0; x < m_map->GetWidth(); x++){
			Sprite* sprite = (*m_entities)[m_map->GetPos(x, y)]->GetSprite();
			if (sprite)
			{
				m_systems.draw_manager->Draw(sprite, x * 64, y * 64);
			}
		}
	}
	for (unsigned int i = 3; i < m_entities->size(); i++)
	{
		if (!(*m_entities)[i]->IsVisible())
			continue;

		Sprite* sprite = (*m_entities)[i]->GetSprite();
		if (sprite)
		{
			m_systems.draw_manager->Draw(sprite,
				(*m_entities)[i]->GetX(),
				(*m_entities)[i]->GetY());
		}
	}
}

State* GameState::NextState()
{
	return nullptr;
}


// private
void GameState::CollisionChecking()
{
	/*Steve* steve = static_cast<Steve*>(m_entities[0]);
	Ball* ball = static_cast<Ball*>(m_entities[1]);

	int overlapX = 0, overlapY = 0;
	if (CollisionManager::Check(ball->GetCollider(), steve->GetCollider(), overlapX, overlapY))
	{
		if (overlapX != 0)
			ball->InvertDirectionX();
		if (overlapY != 0)
			ball->InvertDirectionY();

		ball->SetPosition(ball->GetX() + overlapX, ball->GetY() + overlapY);
	}
	else
	{
		for (unsigned int i = 2; i < m_entities.size(); i++)
		{
			Block* block = static_cast<Block*>(m_entities[i]);
			if (!block->IsVisible())
				continue;

			if (CollisionManager::Check(ball->GetCollider(), block->GetCollider(), overlapX, overlapY))
			{
				block->SetInvisible();

				if (overlapX != 0)
					ball->InvertDirectionX();
				if (overlapY != 0)
					ball->InvertDirectionY();

				ball->SetPosition(ball->GetX() + overlapX, ball->GetY() + overlapY);
			}
		}
	}*/
}
