#ifndef GAME_HPP
#define GAME_HPP
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning = false;
public:
	Game();
	~Game();

	void init(const char* windowTitle, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
};

#endif