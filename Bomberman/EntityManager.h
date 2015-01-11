//EntityManager.h - recycling old entities
#ifndef ENTITYMANAGER_H_INCLUDED
#define ENTITYMANAGER_H_INCLUDED

class Entity;
class SpriteManager;
class InputManager;

class EntityManager
{
public:
	EntityManager(SpriteManager* spriteManager, InputManager* spriteMan);
	~EntityManager();

	std::vector<Entity*>* GetActiveEntities();
	void MakeEntity( int  EntityType , int x , int y);
	void RecycleEntity();
private:
	SpriteManager* m_sprite_manager;
	InputManager* m_input_manager;
	std::vector<Entity*> m_active_entities;
	std::map<int, std::vector<Entity*>> m_inactive_entities;
};
#endif //ENTITYMANAGER_H_INCLUDED