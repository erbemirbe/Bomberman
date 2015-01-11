//map.h
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

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

private:
	int* m_int_map;
	int m_width;
	int m_height;
};



#endif //MAP_H_INCLUDED