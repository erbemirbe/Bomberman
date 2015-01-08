// Steve.h

#ifndef STEVE_H_INCLUDED
#define STEVE_H_INCLUDED

#include "Entity.h"

class keybaord;

class Steve : public Entity
{
public:
	Steve(Keyboard* keyboard, Sprite* sprite, int width, int height);
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
	Keyboard* m_keyboard;
	Sprite* m_sprite;
	Collider* m_collider;

	float m_x;
	float m_y;
	float m_speed;
	int m_screen_width;
	int m_screen_height;
	int m_bombs;
	int m_max_bombs;
	
	void LayBomb();
};

#endif // STEVE_H_INCLUDED
