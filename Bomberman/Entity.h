// Entity.h

#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

enum EEntityType
{
	ENTITY_UNKNOWN,
	ENTITY_PADDLE,
	ENTITY_BLOCK,
	ENTITY_BALL,
};

class Sprite;
class Collider;

class Entity
{
public:
	virtual ~Entity() {}
	virtual void Update(float deltatime) = 0;
	virtual Sprite* GetSprite() = 0;
	virtual Collider* GetCollider() = 0;
	virtual float GetX() = 0;
	virtual float GetY() = 0;
	virtual bool IsVisible() = 0;
	virtual EEntityType GetType() = 0;
};

#endif // ENTITY_H_INCLUDED
