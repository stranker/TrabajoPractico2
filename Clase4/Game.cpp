#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char* windowTitle, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	int flag = 0;
	if (fullscreen)
		flag = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(windowTitle, xpos, ypos, width, height, flag);
		if (window)
			renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;

	}
	else
		isRunning = false;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:	
		break;
	}
}
void Game::update()
{
}
void Game::render()
{

}
void Game::clean()
{

}
bool Game::running()
{
	return isRunning;
}