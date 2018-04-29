#include "Car.h"


Car::Car(const char* texture, SDL_Renderer* renderer, int x, int y, int spd, int lif) : GameObject(texture,renderer,x,y)
{
	speed = spd;
	life = lif;
	setTotalWidthTexture(288);
}

Car::~Car()
{
}

void Car::handleInput(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_s || key == SDLK_DOWN)
			setVelocityY(speed);
		else if (key == SDLK_w || key == SDLK_UP)
			setVelocityY(-speed);
	}
}

void Car::update(float deltaTime)
{
	animateSprite();
	clampObject(20, 20, 100, 500);
	move(0, getVelocityY() * deltaTime);
	
}

