#pragma once
#ifndef VIEWER_H
#define vIEWER_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include "Chess.h"
#include "Button.h"

using namespace std;

class Viewer {
public:
	/*member*/
	SDL_Window* window;
	SDL_Renderer* renderer;
	Button startButt;
	Button readButt;
	Button endButt;
	Button homeButt;
	Button endGameAct;
	Button surrButt;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	SDL_Texture* BOARD_TEXT;
	SDL_Texture* MENU_TEXT;
	SDL_Texture* valid_pos;
	SDL_Texture* curr_red;
	SDL_Texture* curr_bk;
	SDL_Texture* win_red;
	SDL_Texture* win_bk;

	/*constructor*/
	Viewer();

	/*function*/
	void presentScene();
	void blitBackground(SDL_Texture* texture);
	void blitChess(SDL_Texture* texture, SDL_Rect rect);
	void blitButton(int code);
	void blitButtonShadow(int code);
	void blitValidPos(int x, int y);
	void blitCurrentColor(bool curr);
	void blitResult(bool redAlive);
	void renderBoard(vector<Chess*>& chessVec);
	void render(string state, vector<Chess*>& chessVec, vector<Position>& valid, bool curr, bool currColor);
};

#endif // !VIEWER_H