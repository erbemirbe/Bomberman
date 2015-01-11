// MapGenerator.h
#ifndef MAPGENERATOR_H_INCLUDED
#define MAPGENERATOR_H_INCLUDED

class Map;

class MapGenerator {
public:
	MapGenerator();
	~MapGenerator();
	
	Map* LoadMap();
	Map* Gen(int width,int height);

private:
	//int* m_map; delete
};
#endif