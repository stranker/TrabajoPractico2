#include "Wall.h"

Wall::Wall(const char * textureSheet, SDL_Renderer * renderer, int x, int y) : GameObject(textureSheet, renderer, x, y)
{
	setSrcRect(32, 64, 0, 0);
	setScale(2, 2);
	setNewPosition();
	setAnimation(false);
}

Wall::~Wall()
{

}

void Wall::update(float deltaTime)
{
	animateSprite(deltaTime,4,false);
	move(-2, 0);
	colliderUpdate();
	if (isOffScreen())
	{
		setNewPosition();
		isColliding = false;
		setAnimation(false);
		resetSprite();
	}

}

void Wall::hit()
{
	if (!isColliding)
	{
		isColliding = true;
		setAnimation(true);
	}
}
