//mVeloctiyXY.cpp
// Entity module for X and Y directional velocity

#include "stdafx.h"
#include "CVelocityXY.h"

CVelocityXY::CVelocityXY()
{
	m_xVel = 0;
	m_yVel = 0;
	
}

CVelocityXY::CVelocityXY(float xVel, float yVel)
{
	m_xVel = xVel;
	m_yVel = yVel;
	Activate();
}

CVelocityXY::~CVelocityXY()
{

}

float CVelocityXY::GetXVelocity()
{
	return m_xVel;
}

float CVelocityXY::GetYVelocity()
{
	return m_yVel;
}

void CVelocityXY::SetXVelocity(float velocity)
{
	m_xVel = velocity;
	if (velocity == 0 && m_yVel == 0){
		Deactivate();
	}
}

void CVelocityXY::SetYVelocity(float velocity)
{
	if (velocity == 0 && m_xVel == 0){
		Deactivate();
	}
}