//MenuState.h
#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include "State.h"
class Sprite;
class Mouse;
class Button;
class MusicClip;

class MenuState : public State
{
public:
	MenuState(System& system);
	~MenuState();
	bool Update(float deltatime);
	void Draw();
	State* NextState();

private:
	System	m_system;
	bool	m_active;
	State*	m_next_state;
	Mouse*	m_mouse;

	Sprite*				 m_background;
	std::vector<Button*> m_buttons;
	MusicClip*			 m_background_music;
	
};
#endif //MENUSTATE_H_INCLUDED