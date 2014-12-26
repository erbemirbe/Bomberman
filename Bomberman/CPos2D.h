//CPos2D
// Entity component for x,y position
#pragma once

#include "EntityComponent.h"

class CPos2D : public EntityComponent
{
public:
	CPos2D(float x, float y);
	~CPos2D();

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	void SetPos(float x, float y);

private:
	float m_x;
	float m_y;
};