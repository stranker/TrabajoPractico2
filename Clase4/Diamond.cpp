#include "Diamond.h"




Diamond::Diamond(const char * textureSheet, SDL_Renderer * renderer, int x, int y) : GameObject(textureSheet,renderer,x,y)
{
	setSrcRect(16, 16, 0, 0);
	setCollider(0, 0, 16, 16);
	setScale(2, 2);
	picked = false;
	setNewPosition();
	setAnimation(true);
}

Diamond::~Diamond()
{
}

void Diamond::update(float deltaTime)
{
	animateSprite(deltaTime, 3, true);
	colliderUpdate();
	move(-2, 0);
	if (isOffScreen())
		setNewPosition();
}

void Diamond::pickUp()
{
	if (!picked)
	{
		picked = true;
		setNewPosition();
		picked = false;
	}
}
