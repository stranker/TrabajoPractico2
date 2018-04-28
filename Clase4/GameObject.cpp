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
void GameObject::update() 
{
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h*2;
	destRect.w = srcRect.w*2;
	xpos += velocityX;
	ypos += velocityY;

}
void GameObject::render()
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void GameObject::handleInput(SDL_Event event)
{
	if (event.type == SDLK_s)
		velocityY = 1;
	if (event.type == SDLK_w)
		velocityY = -1;
	if (event.type == SDLK_d)
		velocityX = 1;
	if (event.type == SDLK_a)
		velocityX = -1;
}
