#ifndef WALL_H
#define WALL_H
#include "GameObject.h"
#define MAX_WALL_COUNT 5

class Wall :
	public GameObject
{
public:
	Wall(const char* textureSheet, SDL_Renderer* renderer, int x, int y);
	~Wall();
	void update(float deltaTime);
	void hit();
private:
	bool isColliding = false;
};

#endif