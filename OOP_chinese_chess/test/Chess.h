#pragma once
#ifndef CHESS_H
#define CHESS_H

#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

typedef struct {
	int x;
	int y;
}Position;

class Chess {
public:
	/*member*/
	string type;
	string name;
	bool color; //true for red, false for black
	bool alive;
	Position pos;
	SDL_Texture* texture; //image for chess
	SDL_Rect rect;

	/*constructor*/
	Chess();
	Chess(bool color, int x, int y, string type, string name);

	/*function*/
	void move(int x, int y, vector<Position>& valid);
	virtual void findValid(vector<Position>& valid) = 0;

	/*operator overloading*/
	Chess& operator=(const Chess& c);
};

#endif // !CHESS_H