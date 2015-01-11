//Bomb.h
#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED

#include "entity.h"

class Bomb:public Entity
{
public:
	Bomb(Sprite* sprite, int x, int y);
	~Bomb();

	void Reset();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

	void SetPosition(int x, int y);

	void Update(float deltatime);
	void Explode();
	Sprite* GetSprite();

private:
	int m_time;
	int m_blastrange;

	Sprite* m_sprite;
	Collider* m_collider;

};

#endif //BOMB_H_INCLUDED