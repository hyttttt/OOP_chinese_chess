#pragma once
#ifndef CANNON_H
#define CANNON_H
#include "Chess.h"

class Cannon : public Chess {
public:
	/*constructor*/
	Cannon() :Chess() {}
	Cannon(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !CANNON_H