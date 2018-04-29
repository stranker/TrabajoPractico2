#include "GameObject.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* rend, int x, int y)
{
	renderer = rend;
	texture = TextureManager::loadTexture(textureSheet, renderer);
	xpos = x;
	ypos = y;
	velocityX = 0;
	velocityY = 0;
	animationTime = 0;
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

void GameObject::setVelocity(int x, int y)
{
	velocityX = x;
	velocityY = y;
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

int GameObject::getVelocityX()
{
	return velocityX;
}

void GameObject::animateSprite(float deltaTime)
{
	animationTime += deltaTime;
	if (animationTime > 1)
	{
		animationTime = 0;
		setSrcRect(srcRect.h,srcRect.w, srcRect.x, 0);
		if (srcRect.x < totalWidthTexture - srcRect.w)
			srcRect.x += srcRect.w;
		else
			srcRect.x = 0;
	}
	setDestRect(srcRect.h, srcRect.w, xpos, ypos);
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
	else if (xpos >= xMax - srcRect.w)
		xpos = xMax - srcRect.w;
	if (ypos <= yMin)
		ypos = yMin;
	else if (ypos >= yMax - srcRect.h)
		ypos = yMax - srcRect.h;
}

void GameObject::setTotalWidthTexture(int val)
{
	totalWidthTexture = val;
}

void GameObject::createCollider(int h, int w)
{
	collider.h = h;
	collider.w = w;
}

void GameObject::colliderUpdate()
{
	collider.x = xpos;
	collider.y = ypos;
	collider.h = srcRect.h;
	collider.w = srcRect.w;
}
