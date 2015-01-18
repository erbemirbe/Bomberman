//map.h
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

enum EBlockType
{
	BLOCK_WALL,
	BLOCK_GRASS,
	BLOCK_BRICK,
	BLOCK_PWRUP_FIRE,
	BLOCK_PWRUP_SPEED,
	BLOCK_PWRUP_BOMB,
	BLOCK_FIRE,
	BLOCK_BOMB,
};

class Map
{
public:
	Map(int* intMap, int w, int h);
	~Map();
	int GetWidth();
	int GetHeight();
	int Size();
	int* GetIntMap();
	void Print();
	int GetPos(int x, int y);
	void SetPos(int x, int y, int val);

private:
	int* m_int_map;
	int m_width;
	int m_height;
};



#endif //MAP_H_INCLUDED