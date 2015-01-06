//CTile - Entity component for tiles

#pragma once

#include "EntityComponent.h"

class Ctile : public EntityComponent
{
public:
	Ctile(int x, int y);
	~Ctile();

	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();

private:
	int m_x;
	int m_y;
};

