#pragma once
#ifndef SOLDIER_H
#define SOLDIER_H
#include"Chess.h"

class Soldier : public Chess {
public:
	/*constructor*/
	Soldier() :Chess() {}
	Soldier(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !SOLDIER_H