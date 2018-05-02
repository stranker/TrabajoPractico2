#include "Game.h"

int main(int argc, char* argv[]) 
{
	Game* game = new Game();
	game->init("Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	const int FPS = 60;
	const float frameDelay = 1000 / FPS;
	Uint32 frameStart;
	float frameTime = 0;
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update(frameDelay/100);
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
	game->clean();

	return 0;
}