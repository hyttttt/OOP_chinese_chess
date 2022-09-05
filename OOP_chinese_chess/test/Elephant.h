#pragma once
#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "Chess.h"

class Elephant : public Chess {
public:
	/*constructor*/
	Elephant() :Chess() {}
	Elephant(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !ELEPHANT_H