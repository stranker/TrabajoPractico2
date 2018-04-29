#include "Car.h"


Car::Car(const char* texture, SDL_Renderer* renderer, int x, int y, int spd, int lif) : GameObject(texture,renderer,x,y)
{
	speed = spd;
	life = lif;
	setTotalWidthTexture(288);
	setSrcRect(32, 96, 0, 0);
	setDestRect(32, 96, 0, 0);
	createCollider(32, 96);
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
			setVelocity(0,speed);
		else if (key == SDLK_w || key == SDLK_UP)
			setVelocity(0,-speed);
		if (key == SDLK_a || key == SDLK_LEFT)
			setVelocity(-speed, 0);
		else if (key == SDLK_d || key == SDLK_RIGHT)
			setVelocity(speed, 0);
	}
}

void Car::update(float deltaTime)
{
	animateSprite(deltaTime);
	colliderUpdate();
	clampObject(10, 300, 100, 500);
	move(getVelocityX(), getVelocityY());
	
}

