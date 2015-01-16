// GameState.h

#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "State.h"

class Entity;
class EntityManager;
class MapGenerator;
class Map;
class MusicClip;
class SoundClip;
class GameState : public State
{
public:
	GameState(System& system);
	~GameState();

	bool Update(float deltatime);
	void Draw();
	State* NextState();

private:
	void CollisionChecking();

private:
	System					m_systems;
	EntityManager*			m_entity_manager;
	std::vector<Entity*>*	m_entities;
	Map*					m_map;
	bool					m_active;
	MusicClip*				m_background_music;
};

#endif // GAMESTATE_H_INCLUDED
