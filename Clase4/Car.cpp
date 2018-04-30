#include "Car.h"


Car::Car(const char* texture, SDL_Renderer* renderer, int x, int y, int spd, int lif) : GameObject(texture, renderer, x, y)
{
	speed = spd;
	life = lif;
	setSrcRect(32, 96, 0, 0);
	setScale(2, 2);
	setCollider(0, 0, 32, 96);
	setAnimation(true);
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
	animateSprite(deltaTime,3,true);
	colliderUpdate();
	clampObject(10, 300, 100, 500);
	move(getVelocityX(), getVelocityY());
	if (!canBeHit())
		restTime += deltaTime;
	if (restTime >= 25)
	{
		canHit = true;
		restTime = 0;
	}
}

void Car::hit()
{
	if (canHit)
	{
		if (life > 0)
		{
			life--;
			canHit = false;
			cout << "auch" << endl;
		}
	}
	
}

bool Car::isAlive()
{
	return life > 0;
}

bool Car::canBeHit()
{
	return canHit;
}
