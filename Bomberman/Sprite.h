// Sprite.h

#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "EntityComponent.h"

class Sprite : public EntityComponent
{
public:
	Sprite(SDL_Texture* texture);
	~Sprite();

	SDL_Rect* GetRegion();
	SDL_Texture* GetTexture();

protected:
	SDL_Rect m_region;
	SDL_Texture* m_texture;
};

#endif // SPRITE_H_INCLUDED
