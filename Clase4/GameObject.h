#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y);
	~GameObject();
	void update(float deltaTime);
	void render();
	void setVelocityY(int val);
	void move(int x, int y);
	int getYpos();
	int getXpos();
	int getVelocityY();
	void animateSprite();
	void setSrcRect(int h, int w, int x, int y);
	void setDestRect(int h, int w, int x, int y);
	void clampObject(int xMin, int xMax, int yMin, int yMax);
	void setTotalWidthTexture(int val);
private:
	int xpos;
	int ypos;
	int velocityX;
	int velocityY;
	int totalWidthTexture;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
#endif // !GAMEOBJECT_H