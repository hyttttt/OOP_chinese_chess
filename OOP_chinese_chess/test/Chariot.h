#pragma once
#ifndef CHARIOT_H
#define CHARIOT_H
#include "Chess.h"

class Chariot : public Chess {
public:
	/*constructor*/
	Chariot() :Chess() {}
	Chariot(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !CHARIOT_H