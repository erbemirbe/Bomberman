// MapGenerator.h
#ifndef MAPGENERATOR_H_INCLUDED
#define MAPGENERATOR_H_INCLUDED

class MapGenerator {
public:
	MapGenerator(int width, int height);
	void Print();
	void LoadMap();
	~MapGenerator();
	void Gen();

private:
	int* m_map;
	int m_width;
	int m_height;
};
#endif