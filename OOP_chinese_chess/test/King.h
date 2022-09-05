#pragma once
#ifndef KING_H
#define KING_H
#include "Chess.h"

class King : public Chess {
public:
	/*constructor*/
	King() :Chess() {}
	King(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !KING_H