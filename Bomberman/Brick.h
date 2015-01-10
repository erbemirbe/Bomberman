#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED

#include "entity.h"

class Brick :public Entity
{
public:
	Brick(Sprite* sprite, int x, int y);
	~Brick();

	void Reset();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

	void SetPosition(int x, int y);

	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();


private:
	int m_x;
	int m_y;

	bool m_active;

	Sprite* m_sprite;
	Collider* m_collider;

};
#endif //BRICK_H_INCLUDED