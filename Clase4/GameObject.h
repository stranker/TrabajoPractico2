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
	void setVelocity(int x, int y);
	void move(int x, int y);
	int getYpos();
	int getXpos();
	void setScale(float x, float y);
	int getVelocityY();
	int getVelocityX();
	void animateSprite(float deltaTime, int frames, bool loop);
	void setSrcRect(int h, int w, int x, int y);
	void setDestRect(int h, int w, int x, int y);
	void clampObject(int xMin, int xMax, int yMin, int yMax);
	void colliderUpdate();
	SDL_Rect getCollider();
	void setNewPosition();
	void setAnimation(bool val);
	void resetSprite();
	bool isOffScreen();
	void setCollider(int x, int y, int h, int w);
private:
	int xpos;
	int ypos;
	int velocityX;
	int velocityY;
	bool isAnimated = false;
	float scaleX = 1;
	float scaleY = 1;
	float animationTime;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect, collider;
	SDL_Renderer* renderer;
};
#endif // !GAMEOBJECT_H