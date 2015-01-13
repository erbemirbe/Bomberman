if (m_x % 64)
{ //y position is not perfectly aligned with grid
	std::cout << "a" << std::endl;
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
else if (m_map->GetPos(((m_y + 31) / 64), ((m_x + 31) / 64 - 1)) == 1)
{ //Block above is free
	std::cout << "b" << std::endl;
	std::cout << !(m_y % 64) << "true?" << std::endl;
	if (!(m_y % 64))
	{ //Perfectly aligned x-wise
		std::cout << "perfectly aligned" << std::endl;

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
		std::cout << "Not perfect" << std::endl;
		//Get b block
		int b;
		if (m_y % 64 <= 32){
			b = m_map->GetPos(((m_y + 31) / 64) + 1, ((m_x + 31) / 64) - 1);
			std::cout << "x =" << ((m_y + 31) / 64) + 1 << " y = " << ((m_x + 31) / 64) - 1 << " and it is of type:" << b;
		}
		else{
			b = m_map->GetPos(((m_y + 31) / 64) - 1, ((m_x + 31) / 64) - 1);
			std::cout << "x =" << ((m_y + 31) / 64) - 1 << " y = " << ((m_x + 31) / 64) - 1 << " and it is of type:" << b;
		}

		std::cout << m_map->GetPos(2, 4);

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
			std::cout << "B is NOT free" << std::endl;
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
	std::cout << "c" << std::endl;
	if (m_y % 64)
	{ // Perfectly aligned x-wise
		//Get b block
		int b;
		if (m_y % 64 <= 32){
			b = m_map->GetPos(((m_y + 31) / 64) + 1, ((m_x + 31) / 64) - 1);
			std::cout << ((m_y + 31) / 64) + 1 << " " << ((m_x + 31) / 64) - 1 << std::endl;
		}

		else{
			b = m_map->GetPos(((m_y + 31) / 64) - 1, ((m_x + 31) / 64) - 1);
			std::cout << ((m_y + 31) / 64) - 1 << " " << ((m_x + 31) / 64) - 1 << std::endl;
		}

		if (b == 1)
		{ //B is free
			std::cout << "b is free!" << std::endl;
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
				std::cout << "shit is to the left go left" << std::endl;
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