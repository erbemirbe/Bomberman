// Entity.h

#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

enum EEntityType
{
	ENTITY_UNKNOWN,
	ENTITY_STEVE,
	ENTITY_BLOCK,
	ENTITY_BALL,
	ENTITY_BOMB,
	ENTITY_FIRE,
	ENTITY_WALL,
	ENTITY_BRICK,
};

class Sprite;
class Collider;
class EntityManager;

class Entity
{
public:
	Entity();
	virtual ~Entity() {}
	virtual void Update(float deltatime) = 0;//bool?
	virtual Sprite* GetSprite() = 0;
	virtual Collider* GetCollider() = 0;
	virtual float GetX();
	virtual float GetY();
	virtual bool IsVisible() = 0;
	virtual bool IsActive();
	virtual void Activate();
	virtual void Deactivate();
	
	virtual EEntityType GetType() = 0;

	static EntityManager* m_entity_manager;
protected:
	int m_x;
	int m_y;
	bool m_active;
};

#endif // ENTITY_H_INCLUDED
