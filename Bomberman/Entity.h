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
class EntityComponent;

class Entity
{

public:
	Entity();
	virtual ~Entity();

	void AddComponent(std::string, EntityComponent*); //maybe this could return a boolean in the future too indicate if it was added succesfully or not. Dunno
	void RemoveComponent(std::string); //same with this as the above comment...
	//deleting components will be done in the component yo

	/*
		virtual void Update(float deltatime);
		virtual Sprite* GetSprite() = 0;
		virtual Collider* GetCollider() = 0;
		virtual float GetX() = 0;
		virtual float GetY() = 0;
		virtual bool IsVisible() = 0;
		virtual EEntityType GetType() = 0;
	*/
	std::map<std::string, EntityComponent*> m_components;

private:

};

#endif // ENTITY_H_INCLUDED
