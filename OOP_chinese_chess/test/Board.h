#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "King.h"
#include "Advisor.h"
#include "Chariot.h"
#include "Cannon.h"
#include "Elephant.h"
#include "Horse.h"
#include "Soldier.h"
#include <iostream>

using namespace std;

class Board {
public:
	/*member*/
	King rdKing;
	Advisor rdAdvisor1;
	Advisor rdAdvisor2;
	Chariot rdChariot1;
	Chariot rdChariot2;
	Cannon rdCannon1;
	Cannon rdCannon2;
	Elephant rdElephant1;
	Elephant rdElephant2;
	Horse rdHorse1;
	Horse rdHorse2;
	Soldier rdSoldier1;
	Soldier rdSoldier2;
	Soldier rdSoldier3;
	Soldier rdSoldier4;
	Soldier rdSoldier5;
	//black chess
	King bkKing;
	Advisor bkAdvisor1;
	Advisor bkAdvisor2;
	Chariot bkChariot1;
	Chariot bkChariot2;
	Cannon bkCannon1;
	Cannon bkCannon2;
	Elephant bkElephant1;
	Elephant bkElephant2;
	Horse bkHorse1;
	Horse bkHorse2;
	Soldier bkSoldier1;
	Soldier bkSoldier2;
	Soldier bkSoldier3;
	Soldier bkSoldier4;
	Soldier bkSoldier5;

	vector<Chess*> chessVec;
	Chess* chess2dArr[10][9];
	vector<Position> valid;

	/*constructor*/
	Board();

	/*function*/
	void getValid(string name, vector<Position>& valid);
	bool getColor(string name);
	string getType(string name);
	void getPos(string name, int& x, int& y);
	void removeOverlapped(bool color, string type, int x, int y, vector<Position>& valid);
	string checkPressChess(int x, int y);
	bool checkValidPos(int x, int y);
	void moveChess(string name, int destX, int destY);

};

#endif // !BOARD_H