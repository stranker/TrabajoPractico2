#include "GameObject.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* rend, int x, int y)
{
	renderer = rend;
	texture = TextureManager::loadTexture(textureSheet, renderer);
	xpos = x;
	ypos = y;
	velocityX = 0;
	velocityY = 0;
}
GameObject::~GameObject()
{
}
void GameObject::update(float deltaTime) 
{
}
void GameObject::render()
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void GameObject::setVelocityY(int val)
{
	velocityY = val;
}

void GameObject::move(int x, int y)
{
	xpos += x;
	ypos += y;
}

int GameObject::getYpos()
{
	return ypos;
}

int GameObject::getXpos()
{
	return xpos;
}

int GameObject::getVelocityY()
{
	return velocityY;
}

void GameObject::animateSprite()
{
	setSrcRect(32, 96, srcRect.x, 0);
	if (srcRect.x < totalWidthTexture - srcRect.w)
		srcRect.x += srcRect.w;
	else
		srcRect.x = 0;
	cout << srcRect.x << endl;
	setDestRect(32, 96, getXpos(), getYpos());
}

void GameObject::setSrcRect(int h, int w, int x, int y)
{
	srcRect.h = h;
	srcRect.w = w;
	srcRect.x = x;
	srcRect.y = y;
}

void GameObject::setDestRect(int h, int w, int x, int y)
{
	destRect.h = h * 2;
	destRect.w = w * 2;
	destRect.x = x;
	destRect.y = y;
}

void GameObject::clampObject(int xMin, int xMax, int yMin, int yMax)
{
	if (xpos <= xMin)
		xpos = xMin;
	else if (xpos >= xMax)
		xpos = xMax;
	if (ypos <= yMin)
		ypos = yMin;
	else if (ypos >= yMax - destRect.h)
		ypos = yMax - destRect.h;
}

void GameObject::setTotalWidthTexture(int val)
{
	totalWidthTexture = val;
}
