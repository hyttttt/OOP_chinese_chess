#pragma once
#ifndef HORSE_H
#define HORSE_H
#include "Chess.h"

class Horse : public Chess {
public:
	/*constructor*/
	Horse() :Chess() {}
	Horse(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !HORSE_H