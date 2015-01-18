//Fire.h
#ifndef FIRE_H_INCLUDED
#define FIRE_H_INCLUDED

#include "entity.h"

enum EFireDirection
{
	FIRE_UP,
	FIRE_RIGHT,
	FIRE_LEFT,
	FIRE_DOWN,
};

class Map;
class EntityManager;

class Fire :public Entity
{
public:
	Fire(Sprite* sprite, Map* map, EntityManager* entityManager, int x, int y);
	~Fire();

	void Reset();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();
	void SetBlastRangeAndDirection(int blastRange, int fireDir);
	void Blast(int xTile, int yTile, int dir);
	void SetPosition(int x, int y);
	void PowerUp();

	void Update(float deltatime);
	Sprite* GetSprite();

private:
	float m_time;
	int m_blast_range;
	bool m_power_up;
	Sprite* m_sprite;
	Map* m_map;
	EntityManager* m_entity_manager;
	Collider* m_collider;

};

#endif //FIRE_H_INCLUDED