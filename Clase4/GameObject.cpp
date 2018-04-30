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

void GameObject::setScale(float x, float y)
{
	scaleX = x;
	scaleY = y;
}

int GameObject::getVelocityY()
{
	return velocityY;
}

int GameObject::getVelocityX()
{
	return velocityX;
}

void GameObject::animateSprite(float deltaTime, int frames, bool loop)
{
	if (isAnimated)
	{
		animationTime += deltaTime;
		if (animationTime > 1)
		{
			animationTime = 0;
			setSrcRect(srcRect.h, srcRect.w, srcRect.x, 0);
			if (srcRect.x < srcRect.w * (frames - 1))
				srcRect.x += srcRect.w;
			else
			{
				if (loop)
					srcRect.x = 0;
				else
					srcRect.x = srcRect.w * frames - srcRect.w;
			}
		}
	}
	setSrcRect(srcRect.h, srcRect.w, srcRect.x, 0);
	setDestRect(destRect.h, destRect.w, xpos, ypos);
	
}

void GameObject::setSrcRect(int h, int w, int x, int y)
{
	srcRect.h = h;
	srcRect.w = w;
	srcRect.x = x;
	srcRect.y = y;

	destRect.h = h * scaleY;
	destRect.w = w * scaleX;
	destRect.x = x;
	destRect.y = y;
}

void GameObject::setDestRect(int h, int w, int x, int y)
{
	destRect.h = h;
	destRect.w = w;
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

void GameObject::colliderUpdate()
{
	collider.x = xpos;
	collider.y = ypos;
	collider.h = destRect.h;
	collider.w = destRect.w;
}

SDL_Rect GameObject::getCollider()
{
	return collider;
}

void GameObject::setNewPosition()
{
	xpos = 800 + rand() % 1600;
	ypos = 100 + rand() % 400;
}

void GameObject::setAnimation(bool val)
{
	isAnimated = val;
}

void GameObject::resetSprite()
{
	srcRect.x = 0;
}

bool GameObject::isOffScreen()
{
	return getCollider().x + getCollider().w <= 0;
}

void GameObject::setCollider(int x, int y, int h, int w)
{
	collider.x = x;
	collider.y = y;
	collider.h = h * scaleY;
	collider.w = w * scaleX;
}