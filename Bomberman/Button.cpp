//Button.cpp
#include "stdafx.h"
#include "Button.h"

Button::Button(Sprite* sprite, int x, int y, int width, int height){
	m_sprite = sprite;
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}

void Button::Update()
{

}

int Button::GetX()
{
	return m_x;
}
int Button::GetY()
{
	return m_y;
}

int Button::GetWidth()
{
	return m_width;
}

int Button::GetHeight()
{
	return m_height;
}
Sprite* Button::GetSprite()
{
	return m_sprite;
}