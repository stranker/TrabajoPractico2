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

void Game::initializeLabel()
{
	font = TTF_OpenFont("Fonts/Consola.ttf", 22);
	gameOverFont = TTF_OpenFont("Fonts/Consola.ttf", 36);
	fontColor = { 255, 0, 0 };
	scoreLabel = new Label("SCORE ", font, renderer, fontColor, 350, 10);
	livesLabel = new Label("LIVES ", font, renderer, fontColor, 10, 10);
	kmLabel = new Label("KM ", font, renderer, fontColor, 700, 10);
	gameOverLabel = new Label("GAME OVER", gameOverFont, renderer, fontColor, 320, 250);
	restartLabel = new Label("'R' TO RESTART", gameOverFont, renderer, fontColor, 10, 500);
	menuLabel = new Label("'ESC' TO EXIT", gameOverFont, renderer, fontColor, 550, 500);
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
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}
		if ( TTF_Init() == -1)
		{
			cout << "No se inicializo TTF" << endl;
		}
		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		{
			cout << "No se inicializo mixer" << endl;
		}
		isRunning = true;
	}
	initValues();
	
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
		isRunning = false;
	else
		player->handleInput(event);
	if (gameOver)
	{
		if (event.key.keysym.sym == SDLK_r)
		{
			initValues();
		}
		if (event.key.keysym.sym == SDLK_m)
		{

		}
	}
}

void Game::update(float deltaTime)
{
	if (player->getLives()<= 0)
		gameOver = true;
	if (!gameOver)
	{
		player->update(deltaTime);
		km += deltaTime;
		for (int i = 0; i < MAX_DIAMOND_COUNT; i++)
		{
			diamonds[i]->update(deltaTime);
			if (Collision::AABB(player->getCollider(), diamonds[i]->getCollider()))
			{
				diamonds[i]->pickUp();
				score += 100;
				Mix_PlayChannel(-1, diamondSound, 0);
			}
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
					Mix_PlayChannel(-1, wallSound, 0);
				}
			}
		}

		scoreLabel->setText("SCORE " + to_string(score));
		livesLabel->setText("LIVES " + to_string(player->getLives()));
		kmLabel->setText("KM " + to_string(km));
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	for (int i = 0; i < MAX_WALL_COUNT; i++)
		walls[i]->render();
	for (int i = 0; i < MAX_DIAMOND_COUNT; i++)
		diamonds[i]->render();
	scoreLabel->draw();
	kmLabel->draw();
	livesLabel->draw();
	if (gameOver)
	{
		gameOverLabel->draw();
		restartLabel->draw();
		menuLabel->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
	delete player;
}

bool Game::running()
{
	return isRunning;
}

void Game::initValues()
{
	player = new Car("Sprite/PlayerCar.png", renderer, 1, 1, 3, 3);
	intializeDiamonds(renderer);
	intializeWalls(renderer);
	initializeLabel();
	km = 0;
	score = 0;
	lives = player->getLives();
	gameOver = false;
	music = Mix_LoadMUS("Sounds/Music.wav");
	Mix_PlayMusic(music, -1);
	wallSound = Mix_LoadWAV("Sounds/Wall.wav");
	diamondSound = Mix_LoadWAV("Sounds/Diamond.wav");
}
