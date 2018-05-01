#pragma once
#include "GameObject.h"
class Car :	public GameObject
{
public:
	Car(const char* textureSheet, SDL_Renderer* renderer, int x, int y, int speed, int life);
	~Car();
	void handleInput(SDL_Event event);
	void update(float deltaTime);
	void hit();
	bool isAlive();
	bool canBeHit();
	int getLives();
private:
	int speed;
	int life;
	bool canHit = true;
	float restTime = 0;
};

