#include "Label.h"

Label::Label(string txt, TTF_Font* fnt, SDL_Renderer *rend, SDL_Color clr, int xpos, int ypos)
{
	text = txt;
	font = fnt;
	position.x = xpos;
	position.y = ypos;
	renderer = rend;
	color = clr;
}



void Label::setLabelText()
{
	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

void Label::draw()
{
	SDL_RenderCopy(renderer, texture, nullptr, &position);
}

SDL_Color Label::White()
{
	SDL_Color white = { 255,255,255 };
	return white;
}

SDL_Color  Label::Black()
{
	SDL_Color black = {0,0,0};
	return black;
}

SDL_Color  Label::Red()
{
	SDL_Color red = { 255,0,0 };
	return red;
}

Label::~Label()
{
}
