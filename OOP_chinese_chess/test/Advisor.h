#pragma once
#ifndef ADVISOR_H
#define ADVISOR_H
#include "Chess.h"

class Advisor : public Chess {
public:
	/*constructor*/
	Advisor() :Chess() {}
	Advisor(string name, bool color, int x, int y);

	/*function*/
	void findValid(vector<Position>& valid);
};

#endif // !ADVISOR_H