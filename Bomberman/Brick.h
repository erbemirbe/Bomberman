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


private:

	Sprite* m_sprite;
	Collider* m_collider;

};
#endif //BRICK_H_INCLUDED