#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int xpos, int ypos);
	~GameObject();
	void update();
	void render();
	void handleInput(SDL_Event event);
private:
	int xpos;
	int ypos;
	int velocityX;
	int velocityY;
	
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
#endif // !GAMEOBJECT_H