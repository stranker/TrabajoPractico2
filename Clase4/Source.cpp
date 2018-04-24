#include "SDL.h"
#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[]) {

	SDL_Window *window = SDL_CreateWindow("Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer;

	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	return 0;
}