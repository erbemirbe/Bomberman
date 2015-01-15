//Grass.cpp
#include "stdafx.h"
#include "Grass.h"

#include "Collider.h"
#include "Sprite.h"


Grass::Grass(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
}

Grass::~Grass()
{
}

void Grass::Update(float deltatime)
{

}
Sprite* Grass::GetSprite()
{
	return m_sprite;
}
Collider* Grass::GetCollider()
{
	return nullptr;
}
bool Grass::IsVisible()
{
	return true;
}
void Grass::Reset()
{

}
EEntityType Grass::GetType(){
	return ENTITY_GRASS;
}