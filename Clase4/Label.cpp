#include "Label.h"

Label::Label(string txt, TTF_Font* fnt, SDL_Renderer *rend, SDL_Color clr, int xpos, int ypos)
{
	text = txt;
	font = fnt;
	position.x = xpos;
	position.y = ypos;
	renderer = rend;
	color = clr;
	setLabelText();
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

Label::~Label()
{
}

void Label::setText(string txt)
{
	text = txt;
	setLabelText();
}
