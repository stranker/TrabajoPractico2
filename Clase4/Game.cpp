#include "Game.h"

SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
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
	SDL_Surface* tmpSurface = IMG_Load("Sprite/player.png");

	if (tmpSurface == NULL)
	{
		cout << "Error al cargar player" << endl;
	}

	playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
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
	cnt++;
	destR.h = 64;
	destR.w = 64;
	destR.x = cnt;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
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