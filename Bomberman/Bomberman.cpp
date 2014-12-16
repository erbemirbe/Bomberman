// Bomberman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Engine engine;
	if (engine.Initialize())
		engine.Update();
	engine.Shutdown();
	return 0;
}

