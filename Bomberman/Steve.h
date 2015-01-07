// Steve.h

#ifndef STEVE_H_INCLUDED
#define STEVE_H_INCLUDED

#include "Entity.h"

class Mouse;

class Steve : public Entity
{
public:
	Steve(Mouse* mouse, Sprite* sprite, int width, int height);
	~Steve();
	
	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();

	void Reset();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

private:
	Mouse* m_mouse;
	Sprite* m_sprite;
	Collider* m_collider;

	float m_x;
	float m_y;
	float m_speed;
	int m_screen_width;
	int m_screen_height;
};

#endif // STEVE_H_INCLUDED
