//Ctile.cpp - Tile component for entities

#include "stdafx.h"
#include "CTile.h"


Ctile::Ctile(int x, int y)
{
	m_x = x;
	m_y = y;
}

Ctile::~Ctile()
{

}

void Ctile::SetX(int x)
{
	m_x = x;
}

void Ctile::SetY(int y)
{
	m_y = y;
}

int Ctile::GetX()
{
	return m_x;
}

int Ctile::GetY()
{
	return m_y;
}