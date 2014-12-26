//CPos2D.cpp
//Entity module for 2D position

#include "stdafx.h"
#include "CPos2D.h"

CPos2D::CPos2D(float x, float y)
{
	m_x = x;
	m_y = y;
}

float CPos2D::GetX()
{
	return m_x;
}

float CPos2D::GetY()
{
	return m_y;
}

void CPos2D::SetX(float x)
{
	m_x = x;
}

void CPos2D::SetY(float y)
{
	m_y = y;
}

void CPos2D::SetPos(float x, float y)
{
	m_x = x;
	m_y = y;
}