#ifndef LABEL_H
#define LABEL_H
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

class Label
{
public:
	Label(string text, TTF_Font* font, SDL_Renderer *renderer, SDL_Color color, int xpos, int ypos);
	void setLabelText();
	void draw();
	static SDL_Color White();
	static SDL_Color Black();
	static SDL_Color Red();
	~Label();
private:
	string text;
	TTF_Font* font;
	SDL_Rect position;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Color color;
};

#endif // !LABEL_H
