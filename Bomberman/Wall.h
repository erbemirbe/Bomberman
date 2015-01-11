#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "entity.h"

class Wall :public Entity
{
public:
	Wall(Sprite* sprite, int x, int y);
	~Wall();

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
#endif //WALL_H_INCLUDED