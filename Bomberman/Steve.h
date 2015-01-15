// Steve.h

#ifndef STEVE_H_INCLUDED
#define STEVE_H_INCLUDED

#include "Entity.h"

class Keyboard;
class EntityManager;
class Map;


enum EDirection
{
	DIR_NONE,
	DIR_UP,
	DIR_LEFT,
	DIR_DOWN,
	DIR_RIGHT,
};

class Steve : public Entity
{
public:
	Steve(Keyboard* keyboard, EntityManager* entityManager, Map* map, Sprite* sprite, int width, int height);
	~Steve();
	
	void Update(float deltatime);
	Sprite* GetSprite();

	void Reset();
	void ReturnBomb();

	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

private:
	Keyboard* m_keyboard;
	Sprite* m_sprite;
	EntityManager* m_entity_manager;
	Collider* m_collider;
	Map* m_map;

	float m_speed;
	int m_screen_width;
	int m_screen_height;
	int m_bombs;
	int m_max_bombs;
	int m_x_dir;
	int m_y_dir;
	int m_last_movement_key;
	int m_last_movement_key2;
	void LayBomb();
};

#endif // STEVE_H_INCLUDED
