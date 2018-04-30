#ifndef DIAMOND_H
#define DIAMOND_H
#include "GameObject.h"
#define MAX_DIAMOND_COUNT 10

class Diamond :
	public GameObject
{
public:
	Diamond(const char * textureSheet, SDL_Renderer * renderer, int x, int y);
	~Diamond();
	void update(float deltaTime);
	void pickUp();
private:
	bool picked;
};

#endif // !DIAMOND_H