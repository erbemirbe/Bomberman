//Grass.h
#ifndef GRASS_H_INCLUDED
#define GRASS_H_INCLUDED

#include "Entity.h"

class Sprite;

class Grass : public Entity
{
public:
	Grass(Sprite* sprite, int x, int y);
	~Grass();

	void Update(float deltatime);//bool?
	Sprite* GetSprite();
	Collider* GetCollider();
	bool IsVisible();
	void Reset();
	EEntityType GetType();

private:
	Sprite* m_sprite;
};







#endif // GRASS_H_INCLUDED