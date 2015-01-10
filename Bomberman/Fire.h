//Bomb.h
#ifndef FIRE_H_INCLUDED
#define FIRE_H_INCLUDED

#include "entity.h"

class Fire :public Entity
{
public:
	Fire(Sprite* sprite, int x, int y);
	~Fire();

	void Reset();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

	void Activate();
	bool IsActive();
	void SetPosition(int x, int y);

	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();

	

private:
	int m_x;
	int m_y;
	int m_time;
	int m_blastrange;
	
	bool m_active;

	Sprite* m_sprite;
	Collider* m_collider;

};

#endif //FIRE_H_INCLUDED