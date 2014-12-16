// MapGenerator.cpp
#include "stdafx.h"
#include "MapGenerator.h"

#include <iostream>
#include <fstream>
#include <string>

MapGenerator::MapGenerator(const int width, const int height)
{
	m_width = 2 * width + 1;
	m_height = 2 * height + 1;

	m_map = new int[m_width * m_height];
	

	//m_map[0] = 1;
	//m_map[2] = 1;
	//m_map[23] = 1;
	//m_map = nullptr;
	Gen();
}

MapGenerator::~MapGenerator()
{
	delete[] m_map;
}

void MapGenerator::Print()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			std::cout << m_map[y * m_width + x];
		}

		std::cout << std::endl;
	}
}

void MapGenerator::SaveMap(*int[] mat)
{
	std::string coolString = mat;


	std::ofstream coolFile;
	coolFile.open("Example.txt");
	coolFile << "Writing this to a file.\n";
	coolFile.close();




























	/*
	in.open("data.txt");//, std::ios_base::ate);// ate = at end

	if (!in.is_open()) //check if the file exists else quit program
		return;

	unsigned int fileSize = in.tellg();

	in.seekg(0);

	std::string word;
	while (!in.eof()) //eof == end of file
	{
		//std::getline(in, word);
		in >> word; //it takes a word a time
		std::cout << word << std::endl;
	}
	*/
}

void MapGenerator::loadMap()
{
	std::ifstream in;
	in.open("data.txt", std::ios_base::ate);// ate = at end

	if (!in.is_open()) //check if the file exists else quit program
		return 0;

	unsigned int fileSize = in.tellg();

	in.seekg(0);

	std::string word;
	while (!in.eof()) //eof == end of file
	{
		//std::getline(in, word);
		in >> word; //it takes a word a time
		std::cout << word << std::endl;
	}

	in.close();
}

void MapGenerator::Gen()
{
	
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (x % 2 == 1 && y % 2) m_map[y * m_width + x] = 0; 
			else m_map[y * m_width + x] = 1 + rand()%2;
		}
	}
	m_map[0 * m_width + 0] = 1;
	m_map[1 * m_width + 0] = 1;
	m_map[0 * m_width + 1] = 1;
}