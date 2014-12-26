//CVelocityXY.h
// Entity module for X and Y directional velocity
#pragma once

#include "EntityComponent.h"

class CVelocityXY : public EntityComponent
{
public:
	CVelocityXY();
	CVelocityXY(float xVel, float yVel);

	~CVelocityXY();

	float GetXVelocity();
	float GetYVelocity();

	void SetXVelocity(float velocity);
	void SetYVelocity(float velocity);

private:
	float m_xVel, m_yVel;
};