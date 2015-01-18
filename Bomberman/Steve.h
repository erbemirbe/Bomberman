// Steve.h

#ifndef STEVE_H_INCLUDED
#define STEVE_H_INCLUDED

#include "Entity.h"

class Keyboard;
class EntityManager;
class Map;


enum EDirection
{
	KEY_NONE,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_BOMB,
};

class Steve : public Entity
{
public:
	Steve(Keyboard* keyboard, EntityManager* entityManager, Map* map, Sprite* sprite,std::map<int,int>* controls, int x, int y);
	~Steve();
	
	void Update(float deltatime);
	Sprite* GetSprite();

	void Reset();
	void SetName(std::string name);
	void ReturnBomb();
	int GetBlastRange();
	bool IsVisible();
	EEntityType GetType();
	Collider* GetCollider();

private:
	Keyboard* m_keyboard;
	Sprite* m_sprite;
	EntityManager* m_entity_manager;
	Collider* m_collider;
	Map* m_map;

	int m_c_up;
	int m_c_right;
	int m_c_left;
	int m_c_down;
	int m_c_bomb;

	std::string m_name;
	float m_speed;
	int m_screen_width;
	int m_screen_height;
	int m_bombs;
	int m_max_bombs;
	int m_blast_range;
	int m_x_dir;
	int m_y_dir;
	int m_last_movement_key;
	int m_last_movement_key2;
	void LayBomb();
};

#endif // STEVE_H_INCLUDED
