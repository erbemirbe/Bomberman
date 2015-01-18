//Bomb.h
#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED

#include "entity.h"

class EntityManager;
class Steve;
class Map;

class Bomb:public Entity
{
public:
	Bomb(Sprite* sprite, EntityManager* EntityManager, Map* map, int x, int y);
	~Bomb();

	void Reset(int x, int y);
	void Reset();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

	void SetOwner(Steve*);

	void SetPosition(int x, int y);

	void Update(float deltatime);
	void Explode();
	Sprite* GetSprite();

private:
	float m_time;
	int m_blast_range;

	Sprite* m_sprite;
	Collider* m_collider;
	Steve* m_owner;
	EntityManager* m_entity_manager;
	Map* m_map;
};

#endif //BOMB_H_INCLUDED