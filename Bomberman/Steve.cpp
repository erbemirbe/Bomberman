// Steve.cpp

#include "stdafx.h"

#include "Sprite.h"
#include "Keyboard.h"
#include "Collider.h"
#include "Map.h"
#include "Steve.h"
#include <iostream>


Steve::Steve(Keyboard* keyboard, Map* map, Sprite* sprite, int x, int y)
{
	m_keyboard = keyboard;
	m_sprite = sprite;

	m_collider = new Collider(0, 0);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w, 
		m_sprite->GetRegion()->h);
	m_map = map;

	m_x = x;
	m_y = y;

	m_speed = 150.0f;

	m_bombs = 0;
	m_max_bombs = 3;
	
	Reset();
}

Steve::~Steve()
{
	if (m_collider)
		delete m_collider;
}

void Steve::Update(float deltatime)
{
	if (m_keyboard->IsKeyDownOnce(SDLK_w))
	{
		m_last_movement_key2 = m_last_movement_key;
		 m_last_movement_key = DIR_UP;
	}
	else if (m_keyboard->IsKeyDownOnce(SDLK_a))
	{
		m_last_movement_key2 = m_last_movement_key;
		m_last_movement_key = DIR_LEFT;
	}
	else if (m_keyboard->IsKeyDownOnce(SDLK_s))
	{
		m_last_movement_key2 = m_last_movement_key;
		m_last_movement_key = DIR_DOWN;
	}
	else if (m_keyboard->IsKeyDownOnce(SDLK_d))
	{
		m_last_movement_key2 = m_last_movement_key;
		m_last_movement_key = DIR_RIGHT;
	}
	else
	{
		if (!m_keyboard->IsKeyDown(SDLK_w) &&
			!m_keyboard->IsKeyDown(SDLK_a) &&
			!m_keyboard->IsKeyDown(SDLK_s) &&
			!m_keyboard->IsKeyDown(SDLK_d)
		)
			m_last_movement_key = DIR_NONE;
	}
	std::cout << m_last_movement_key2 << std::endl;

	int movement = m_speed * deltatime;

	/* Testing key
	if (m_keyboard->IsKeyDown(SDLK_f)){
		std::cout <<" pos" << m_x << " " << m_y << std::endl;
		std::cout << "grid " << (m_x + 31) / 64 << " " << (m_y + 31) / 64 << std::endl;
		std::cout << m_x % 64 << std::endl;
	}*/
		
	//(m_x+31)%64;
	if (m_last_movement_key == DIR_UP)
	{
		if (m_y % 64)
		{ //y position is not perfectly aligned with grid
			//std::cout << "a" << std::endl;
			if (m_y % 64 - movement < 0)
			{ //Will cross grid
				//Snap to the edge (to fix: and calculate how much movement you have left and loop)
				m_y -= m_y % 64;
			}
			else
			{ //Will not cross grid
				//move the whole movement
				m_y -= movement;
			}
		}
		else if (m_map->GetPos( ((m_x + 31) / 64),  ((m_y + 31) / 64 - 1) ) == 1)
		{ //Block above is free
			//std::cout << "b" << std::endl;
			//std::cout << !(m_x % 64)<< "true?" << std::endl;
			if (!(m_x % 64))
			{ //Perfectly aligned x-wise
				//std::cout << "perfectly aligned" << std::endl;

				//if (m_y % 64 - movement < 0)
				//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
				//	m_y -= m_y % 64;
				//}
				//else
				//{ //move the whole movement
					m_y -= movement;
				//}
			}
			else
			{ //Not perfectly aligned x-wise
				//std::cout << "Not perfect" << std::endl;
				//Get b block
				int b;
				if (m_x % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64)+1, ((m_y + 31) / 64) -1);
					//std::cout << "x =" << ((m_x + 31) / 64) + 1 << " y = " << ((m_y + 31) / 64) - 1 << " and it is of type:" << b;
				}
				else{
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) - 1);
					//std::cout << "x =" << ((m_x + 31) / 64) - 1 << " y = " << ((m_y + 31) / 64) - 1 << " and it is of type:" << b;
				}

				//std::cout << m_map->GetPos(2, 4);

				if (b == 1)
				{ //B is free
					//std::cout << " is free.. Look by yourself: "<< b << std::endl;
					//if (m_y % 64 - movement < 0)
					//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
					//	std::cout << "oh snap" << std::endl;
					//	m_y -= m_y % 64;
					//}
					//else
					//{ //move the whole movement
						//std::cout <<  << std::endl;
						m_y -= movement;
					//}
				}
				else
				{ // B is not free
					//std::cout << "B is NOT free" << std::endl;
					if (m_x % 64 <= 32)
					{ //A block is to the left. (might be the reverse)
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x -= m_x % 64;
						}
						else
						{ //move the whole movement
							m_x -= movement;
						}
					}
					else
					{ //A block is to the right
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x += m_x % 64;
						}
						else
						{ //move the whole movement
							m_x += movement;
						}
					}
				}
			}
		}
		else
		{ //A is blocked
			//std::cout << "c" << std::endl;
			if (m_x % 64)
			{ // Perfectly aligned x-wise
				//Get b block
				int b;
				if (m_x % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) - 1);
					//std::cout << ((m_x + 31) / 64) + 1 << " " << ((m_y + 31) / 64) - 1 << std::endl;
				}
					
				else{
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) - 1);
					//std::cout << ((m_x + 31) / 64) -1 << " " << ((m_y + 31) / 64) - 1 << std::endl;
				}

				if (b == 1)
				{ //B is free
					//std::cout << "b is free!" << std::endl;
					if (m_x % 64 <= 32)
					{ //B block is to the right. (might be the reverse)
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x += m_x % 64;
						}
						else
						{ //move the whole movement
							m_x += movement;
						}
					}
					else
					{ //B block is to the left
						//std::cout << "shit is to the left go left" << std::endl;
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x -= m_x % 64;
						}
						else
						{ //move the whole movement
							m_x -= movement;
						}
					}
				}
				else
				{
					movement = 0;
					//break;
				}
			}
			else
			{
				movement = 0;
				//break;
			}

		}
	}
	if (m_last_movement_key == DIR_LEFT)
	{
		if (m_x % 64)
		{ //y position is not perfectly aligned with grid
			//std::cout << "a" << std::endl;
			if (m_x % 64 - movement < 0)
			{ //Will cross grid
				//Snap to the edge (to fix: and calculate how much movement you have left and loop)
				m_x -= m_x % 64;
			}
			else
			{ //Will not cross grid
				//move the whole movement
				m_x -= movement;
			}
		}
		else if (m_map->GetPos(((m_x + 31) / 64 - 1), ((m_y + 31) / 64)) == 1)
		{ //Block above is free
			//std::cout << "b" << std::endl;
			//std::cout << !(m_y % 64) << "true?" << std::endl;
			if (!(m_y % 64))
			{ //Perfectly aligned x-wise
				//std::cout << "perfectly aligned" << std::endl;

				//if (m_x % 64 - movement < 0)
				//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
				//	m_x -= m_x % 64;
				//}
				//else
				//{ //move the whole movement
				m_x -= movement;
				//}
			}
			else
			{ //Not perfectly aligned x-wise
				//std::cout << "Not perfect" << std::endl;
				//Get b block
				int b;
				if (m_y % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) + 1);
					//std::cout << "x = " << ((m_y + 31) / 64) + 1 << " y = " << ((m_x + 31) / 64) - 1 << " and it is of type:" << b;
				}
				else{
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) - 1);
					//std::cout << "x = " << ((m_y + 31) / 64) - 1 << " y = " << ((m_x + 31) / 64) - 1 << " and it is of type:" << b;
				}

				//std::cout << m_map->GetPos(2, 4);

				if (b == 1)
				{ //B is free
					//std::cout << " is free.. Look by yourself: "<< b << std::endl;
					//if (m_x % 64 - movement < 0)
					//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
					//	std::cout << "oh snap" << std::endl;
					//	m_x -= m_x % 64;
					//}
					//else
					//{ //move the whole movement
					//std::cout <<  << std::endl;
					m_x -= movement;
					//}
				}
				else
				{ // B is not free
					//std::cout << "B is NOT free" << std::endl;
					if (m_y % 64 <= 32)
					{ //A block is to the left. (might be the reverse)
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y -= m_y % 64;
						}
						else
						{ //move the whole movement
							m_y -= movement;
						}
					}
					else
					{ //A block is to the right
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y += m_y % 64;
						}
						else
						{ //move the whole movement
							m_y += movement;
						}
					}
				}
			}
		}
		else
		{ //A is blocked
			//std::cout << "c" << std::endl;
			if (m_y % 64)
			{ // Perfectly aligned x-wise
				//Get b block
				int b;
				if (m_y % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) + 1);
					//std::cout << ((m_y + 31) / 64) + 1 << " " << ((m_x + 31) / 64) - 1 << std::endl;
				}

				else{
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) - 1);
					//std::cout << ((m_y + 31) / 64) - 1 << " " << ((m_x + 31) / 64) - 1 << std::endl;
				}

				if (b == 1)
				{ //B is free
					//std::cout << "b is free!" << std::endl;
					if (m_y % 64 <= 32)
					{ //B block is to the right. (might be the reverse)
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y += m_y % 64;
						}
						else
						{ //move the whole movement
							m_y += movement;
						}
					}
					else
					{ //B block is to the left
						//std::cout << "shit is to the left go left" << std::endl;
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y -= m_y % 64;
						}
						else
						{ //move the whole movement
							m_y -= movement;
						}
					}
				}
				else
				{
					movement = 0;
					//break;
				}
			}
			else
			{
				movement = 0;
				//break;
			}

		}
	}
	if (m_last_movement_key == DIR_DOWN)
	{
		if (m_y % 64)
		{ //y position is not perfectly aligned with grid
			//std::cout << "a" << std::endl;
			if (m_y % 64 - movement < 0)
			{ //Will cross grid
				//Snap to the edge (to fix: and calculate how much movement you have left and loop)
				m_y += m_y % 64;
			}
			else
			{ //Will not cross grid
				//move the whole movement
				m_y += movement;
			}
		}
		else if (m_map->GetPos(((m_x + 31) / 64), ((m_y + 31) / 64 + 1)) == 1)
		{ //Block above is free
			//std::cout << "b" << std::endl;
			//std::cout << !(m_x % 64) << "true?" << std::endl;
			if (!(m_x % 64))
			{ //Perfectly aligned x-wise
				//std::cout << "perfectly aligned" << std::endl;

				//if (m_y % 64 - movement < 0)
				//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
				//	m_y -= m_y % 64;
				//}
				//else
				//{ //move the whole movement
				m_y += movement;
				//}
			}
			else
			{ //Not perfectly aligned x-wise
				//std::cout << "Not perfect" << std::endl;
				//Get b block
				int b;
				if (m_x % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) + 1);
					//std::cout << "x =" << ((m_x + 31) / 64) + 1 << " y = " << ((m_y + 31) / 64) - 1 << " and it is of type:" << b;
				}
				else{
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) + 1);
					//std::cout << "x =" << ((m_x + 31) / 64) - 1 << " y = " << ((m_y + 31) / 64) - 1 << " and it is of type:" << b;
				}

				//std::cout << m_map->GetPos(2, 4);

				if (b == 1)
				{ //B is free
					//std::cout << " is free.. Look by yourself: "<< b << std::endl;
					//if (m_y % 64 - movement < 0)
					//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
					//	std::cout << "oh snap" << std::endl;
					//	m_y -= m_y % 64;
					//}
					//else
					//{ //move the whole movement
					//std::cout <<  << std::endl;
					m_y += movement;
					//}
				}
				else
				{ // B is not free
					//std::cout << "B is NOT free" << std::endl;
					if (m_x % 64 <= 32)
					{ //A block is to the left. (might be the reverse)
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x -= m_x % 64;
						}
						else
						{ //move the whole movement
							m_x -= movement;
						}
					}
					else
					{ //A block is to the right
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x += m_x % 64;
						}
						else
						{ //move the whole movement
							m_x += movement;
						}
					}
				}
			}
		}
		else
		{ //A is blocked
			//std::cout << "c" << std::endl;
			if (m_x % 64)
			{ // Perfectly aligned x-wise
				//Get b block
				int b;
				if (m_x % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) + 1);
					//std::cout << ((m_x + 31) / 64) + 1 << " " << ((m_y + 31) / 64) - 1 << std::endl;
				}

				else{
					b = m_map->GetPos(((m_x + 31) / 64) - 1, ((m_y + 31) / 64) + 1);
					//std::cout << ((m_x + 31) / 64) - 1 << " " << ((m_y + 31) / 64) - 1 << std::endl;
				}

				if (b == 1)
				{ //B is free
					//std::cout << "b is free!" << std::endl;
					if (m_x % 64 <= 32)
					{ //B block is to the right. (might be the reverse)
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x += m_x % 64;
						}
						else
						{ //move the whole movement
							m_x += movement;
						}
					}
					else
					{ //B block is to the left
						//std::cout << "shit is to the left go left" << std::endl;
						if (m_x % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_x -= m_x % 64;
						}
						else
						{ //move the whole movement
							m_x -= movement;
						}
					}
				}
				else
				{
					movement = 0;
					//break;
				}
			}
			else
			{
				movement = 0;
				//break;
			}

		}
	}
	if (m_last_movement_key == DIR_RIGHT)
	{
		if (m_x % 64)
		{ //y position is not perfectly aligned with grid
			//std::cout << "a" << std::endl;
			if (m_x % 64 - movement < 0)
			{ //Will cross grid
				//Snap to the edge (to fix: and calculate how much movement you have left and loop)
				m_x += m_x % 64;
			}
			else
			{ //Will not cross grid
				//move the whole movement
				m_x += movement;
			}
		}
		else if (m_map->GetPos(((m_x + 31) / 64 + 1), ((m_y + 31) / 64)) == 1)
		{ //Block above is free
			//std::cout << "b" << std::endl;
			//std::cout << !(m_y % 64) << "true?" << std::endl;
			if (!(m_y % 64))
			{ //Perfectly aligned x-wise
				//std::cout << "perfectly aligned" << std::endl;

				//if (m_x % 64 - movement < 0)
				//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
				//	m_x -= m_x % 64;
				//}
				//else
				//{ //move the whole movement
				m_x += movement;
				//}
			}
			else
			{ //Not perfectly aligned x-wise
				//std::cout << "Not perfect" << std::endl;
				//Get b block
				int b;
				if (m_y % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) + 1);
					//std::cout << "x = " << ((m_y + 31) / 64) + 1 << " y = " << ((m_x + 31) / 64) - 1 << " and it is of type:" << b;
				}
				else{
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) - 1);
					//std::cout << "x = " << ((m_y + 31) / 64) - 1 << " y = " << ((m_x + 31) / 64) - 1 << " and it is of type:" << b;
				}

				//std::cout << m_map->GetPos(2, 4);

				if (b == 1)
				{ //B is free
					//std::cout << " is free.. Look by yourself: "<< b << std::endl;
					//if (m_x % 64 - movement < 0)
					//{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
					//	std::cout << "oh snap" << std::endl;
					//	m_x -= m_x % 64;
					//}
					//else
					//{ //move the whole movement
					//std::cout <<  << std::endl;
					m_x += movement;
					//}
				}
				else
				{ // B is not free
					//std::cout << "B is NOT free" << std::endl;
					if (m_y % 64 <= 32)
					{ //A block is to the left. (might be the reverse)
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y -= m_y % 64;
						}
						else
						{ //move the whole movement
							m_y -= movement;
						}
					}
					else
					{ //A block is to the right
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y += m_y % 64;
						}
						else
						{ //move the whole movement
							m_y += movement;
						}
					}
				}
			}
		}
		else
		{ //A is blocked
			//std::cout << "c" << std::endl;
			if (m_y % 64)
			{ // Perfectly aligned x-wise
				//Get b block
				int b;
				if (m_y % 64 <= 32){
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) + 1);
					//std::cout << ((m_y + 31) / 64) + 1 << " " << ((m_x + 31) / 64) - 1 << std::endl;
				}

				else{
					b = m_map->GetPos(((m_x + 31) / 64) + 1, ((m_y + 31) / 64) - 1);
					//std::cout << ((m_y + 31) / 64) - 1 << " " << ((m_x + 31) / 64) - 1 << std::endl;
				}

				if (b == 1)
				{ //B is free
					//std::cout << "b is free!" << std::endl;
					if (m_y % 64 <= 32)
					{ //B block is to the right. (might be the reverse)
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y += m_y % 64;
						}
						else
						{ //move the whole movement
							m_y += movement;
						}
					}
					else
					{ //B block is to the left
						//std::cout << "shit is to the left go left" << std::endl;
						if (m_y % 64 - movement < 0)
						{ //Snap to the edge (to fix: and calculate how much movement you have left and loop)
							m_y -= m_y % 64;
						}
						else
						{ //move the whole movement
							m_y -= movement;
						}
					}
				}
				else
				{
					movement = 0;
					//break;
				}
			}
			else
			{
				movement = 0;
				//break;
			}
		}
	}
	if (m_keyboard->IsKeyDown(SDLK_v)) LayBomb();
	//move();
}

void move(){
	//	if ()
	//m_keyboard;
	/*float deltaX = m_mouse->GetX() - (m_x + static_cast<float>(m_sprite->GetRegion()->w * 0.5f));
	if (static_cast<int>(deltaX) != 0)
	{
	float dirX = deltaX / abs(deltaX);
	m_x += m_speed * abs(deltaX) * deltatime * dirX;

	if (m_x < 0.0f)
	m_x = 0.0f;
	else if (m_x > m_screen_width - 80.0f)
	m_x = m_screen_width - 80.0f;

	m_collider->SetPosition(m_x, m_y);
	}*/
	//std::cout << (m_x) % 64 << std::endl;
	//std::cout << (m_x + 32) / 64 << " " << (m_y + 32) / 64 << std::endl;
	/*
	//the amount of movement
	int movement = m_speed * deltatime;

	//how to get x and y position
	//m_int_map[y * m_width + x];


	if (m_y % 64){ //y position is not perfectly aligned with grid
		if (m_y % 64 - movement < 0){
			m_y -= m_y % 64;
		} else {
			m_y -= movement;
		}
	}
	else if (m_x % 64){ //both x and y positions are perfectly aligned with a tile
		if (m_map->GetIntMap()[((m_y + 32) / 64 - 1) * m_map->GetWidth() + ((m_x + 32) / 64)] == BLOCK_GRASS) { //tile above is free
			if (m_y % 64 - movement < 0){
				m_y -= m_y % 64;
			} else {
				m_y -= movement;
			}
		}
	} else { //only y is perfectly aligned

	if (!(m_x + 32) % 64 == 0){ //
	if ((m_x + 32) % 64 > 32 && m_map->GetIntMap()[((m_y + 32) / 64 - 1) * m_map->GetWidth() + ((m_x + 32) / 64 + 1)] == BLOCK_GRASS)
	{
		if (m_x % 64 + movement < 0)
		{
			m_x += m_x % 64;
			std::cout << "a" << std::endl;
		}
		else
		{
			m_x += movement;
			std::cout << "b" << std::endl;
		}
	}
	else if (m_map->GetIntMap()[((m_y + 32) / 64 - 1) * m_map->GetWidth() + ((m_x + 32) / 64 - 1)] == BLOCK_GRASS)
	{
		if (m_x % 64 - movement < 0){
			m_x -= m_x % 64;
			std::cout << "d" << std::endl;
		}
		else
		{
			m_x -= movement;
			std::cout << "e" << std::endl;
		}
	}
	}
	}
	/*if()
	{

	}
	*/
	/*
	A IS FREE PERFECTLY ALIGNED
		MOVE TOWARDS A

	A IS FREE NOT PERFECTLY ALIGNED
		B IS FREE
			MOVE TOWARDS A
		ALIGN THEN MOVE TOWARDS A

	A IS BLOCKED PERFECTLY ALIGNED
		NOTHING

	A IS BLOCKED NOT PERFECTLY ALIGNED
		B IS FREE
			ALIGN WITH B THEN MOVE TOWARDS B

		B IS BLOCKED
			DON'T MOVE
	*/
	//if (m_map->GetIntMap()[((m_y + 32) / 64 + 1) * m_map->GetWidth() + ((m_x + 32) / 64)] == 1)
	//{
}

void Steve::LayBomb()
{
	if (m_bombs < m_max_bombs)
	{
		m_y++;
	}
}

Sprite* Steve::GetSprite()
{
	return m_sprite;
}

Collider* Steve::GetCollider()
{
	return m_collider;
}

void Steve::Reset()
{
	m_collider->SetPosition(m_x, m_y);
}

bool Steve::IsVisible() 
{
	return true;
}

EEntityType Steve::GetType()
{
	return ENTITY_STEVE;
}
