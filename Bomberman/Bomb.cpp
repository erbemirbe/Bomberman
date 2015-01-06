//Bomb.cpp
#include "stdafx.h"
#include "bomb.h"

#include "EntityComponent.h"
#include "CPos2D.h"

#include <string>

Bomb::Bomb()
{
	//everything in this costructor might be useless since I am creating things through the entity manager instead of in their own classes
	//std::string position = "position";
	//CPos2D a(1, 1);
	//m_components.insert(std::pair<std::string, SDL_Texture*>( position, a));
	//position
	//timer
	//
}

Bomb::~Bomb()
{

}