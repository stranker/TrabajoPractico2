#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H


#include "Game.h"

class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
};

#endif // !TEXTUREMANAGER_H