//Button.h
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

class Sprite;

class Button
{
public:
	Button(Sprite* sprite, int x, int y, int width, int height);
	~Button();

	void Update();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	Sprite* GetSprite();

private:
	Sprite* m_sprite;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};

#endif // BUTTON_H_INCLUDED
