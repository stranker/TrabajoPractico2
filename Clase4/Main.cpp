#include "SDL.h"
#include "Game.h"

int main(int argc, char* argv[]) 
{
	Game* game = new Game();
	game->init("Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frameStart)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();

	return 0;
}