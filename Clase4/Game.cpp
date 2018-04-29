#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Car.h"

Car* player;

int cnt = 0;

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
	player = new Car("Sprite/PlayerCar.png", renderer, 1, 1, 2, 3);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		isRunning = false;
	else
		player->handleInput(event);
}

void Game::update(float deltaTime)
{
	player->update(deltaTime);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running()
{
	return isRunning;
}