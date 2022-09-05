#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Button {
public:
	/*member*/
	SDL_Rect buttonRect;
	SDL_Texture* texture;

	/*constructor*/
	Button();
	//Button(int x, int y);
	//Button(int x, int y, int w, int h);
};

#endif // !BUTTON_H