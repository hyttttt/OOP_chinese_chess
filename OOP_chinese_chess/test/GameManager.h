#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Viewer.h"
#include "Board.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class GameManager {
public:
	/*member*/
	bool running;
	string state;
	Viewer gameViewer;
	Board* gameBoard;
	string currentPick;
	bool currentColor; //true for red, false for black
	bool newGame;

	/*function*/
	bool initGame();
	void exitGame();
	void printGame();
	void gameLoop();
	void checkWinner();
	void eventHandler(SDL_Event* newEvent);
	void loadChessImg();

	/*constructor*/
	GameManager();
	
};

#endif // !GAME_MANAGER_H