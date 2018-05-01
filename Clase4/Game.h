#ifndef GAME_HPP
#define GAME_HPP
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <ctime>
#include "Label.h"
#include <string> 

using namespace std;

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning = false;
	bool gameOver = false;
	Label *scoreLabel, *livesLabel, *kmLabel, *gameOverLabel, *restartLabel, *menuLabel;
	SDL_Color fontColor;
	TTF_Font *font, *gameOverFont;
	int score;
	float km;
	int lives;
	void initializeLabel();
	Mix_Music *music;
	Mix_Chunk *diamondSound;
	Mix_Chunk *carSound;
	Mix_Chunk *wallSound;
public:
	Game();
	~Game();

	void init(const char* windowTitle, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update(float deltaTime);
	void render();
	void clean();
	bool running();
	void initValues();
};

#endif