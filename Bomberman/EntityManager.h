//EntityManager.h - recycling old entities
#ifndef ENTITYMANAGER_H_INCLUDED
#define ENTITYMANAGER_H_INCLUDED

class Entity;
class SpriteManager;
class InputManager;
class SoundManager;
class Map;

class EntityManager
{
public:
	EntityManager(SpriteManager* spriteManager, InputManager* spriteMan, Map* map, SoundManager* soundManager);
	~EntityManager();

	std::vector<Entity*>* GetActiveEntities();
	Entity* MakeEntity( int  EntityType , int x , int y);
	void RecycleEntity(Entity*);
private:
	SpriteManager*						m_sprite_manager;
	InputManager*						m_input_manager;
	Map*								m_map;
	std::vector<Entity*>				m_active_entities;
	std::map<int, std::vector<Entity*>*> m_inactive_entities;
	SoundManager*						m_sound_manager;
};
#endif //ENTITYMANAGER_H_INCLUDED