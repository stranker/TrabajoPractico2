#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Car.h"
#include "Collision.h"
#include "Diamond.h"
#include "Wall.h"
#include "Label.h"

Car* player;
Diamond* diamonds[MAX_DIAMOND_COUNT];
Wall* walls[MAX_WALL_COUNT];
TTF_Font* font;
Label* testLabel;

void intializeDiamonds(SDL_Renderer* renderer)
{
	for (int i = 0; i < MAX_DIAMOND_COUNT; i++)
		diamonds[i] = new Diamond("Sprite/Diamond.png",renderer,0,0);
}

void intializeWalls(SDL_Renderer* renderer)
{
	for (int i = 0; i < MAX_WALL_COUNT; i++)
		walls[i] = new Wall("Sprite/Wall.png", renderer, 0, 0);
}

void initializeLabels(SDL_Renderer* renderer)
{
	font = TTF_OpenFont("Fonts/Consola.ttf", 24);
	SDL_Color red = { 255,0,0 };
	testLabel = new Label("prueba", font, renderer, red, 100, 100);
	testLabel->setLabelText();
}

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
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(windowTitle, xpos, ypos, width, height, flag);
		if (window)
			renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		if (!IMG_Init(IMG_INIT_PNG))
		{
			cout << "Error al inicializar IMG" << endl;
		}
		if ( TTF_Init() == 0)
		{
			isRunning = true;
		}
	}
	player = new Car("Sprite/PlayerCar.png", renderer, 1, 1, 2, 3);
	intializeDiamonds(renderer);
	intializeWalls(renderer);
	initializeLabels(renderer);
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
	for (int i = 0; i < MAX_DIAMOND_COUNT; i++)
	{
		diamonds[i]->update(deltaTime);
		if (Collision::AABB(player->getCollider(), diamonds[i]->getCollider()))
			diamonds[i]->pickUp();
	}
	for (int i = 0; i < MAX_WALL_COUNT; i++)
	{
		walls[i]->update(deltaTime);
		if (Collision::AABB(player->getCollider(), walls[i]->getCollider()))
		{
			if (player->canBeHit())
			{
				player->hit();
				walls[i]->hit();
			}
		}
	}

	/*if (!player->isAlive())
	{
		isRunning = false;
	}*/
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	for (int i = 0; i < MAX_WALL_COUNT; i++)
		walls[i]->render();
	for (int i = 0; i < MAX_DIAMOND_COUNT; i++)
		diamonds[i]->render();
	testLabel->draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete player;
}

bool Game::running()
{
	return isRunning;
}