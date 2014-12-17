// Bomberman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "MapGenerator.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{

	MapGenerator m(10,5);
	//m.SaveMap();
	
	m.LoadMap();
	m.Print();
	std::cin.get();



	/*
	Engine engine;
	if (engine.Initialize())
		engine.Update();
	engine.Shutdown();
	*/
	return 0;
}

