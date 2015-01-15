//FireRoot.h
#ifndef FIREROOT_H_INCLUDED
#define FIREROOT_H_INCLUDED

#include "entity.h"

class Map;

class FireRoot :public Entity
{
public:
	FireRoot(Sprite* sprite, Map* map, EntityManager* entityManager, int x, int y);
	~FireRoot();

	void Reset();
	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();
	void SetPosition(int x, int y);
	void Update(float deltatime);
	Sprite* GetSprite();
	void SetBlastRange(int blastRange);
	void Init();
	void Blast(int xGrid, int yGrid, int dir);

private:
	float m_time;
	int m_blast_range;

	Sprite* m_sprite;
	Map* m_map;
	Collider* m_collider;
	EntityManager* m_entity_manager;

};

#endif //FIRE_H_INCLUDED