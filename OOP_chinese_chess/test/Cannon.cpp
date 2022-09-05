#include "Cannon.h"

Cannon::Cannon(string name, bool color, int x, int y) :Chess(color, x, y, "cannon", name) {}

void Cannon::findValid(vector<Position>& valid) {
	//horizonal
	for (int x = 0; x < 9; x++) {
		Position ph;
		ph.x = x;
		ph.y = this->pos.y;

		if (x != this->pos.x)
			valid.push_back(ph);
	}

	//vertical
	for (int y = 0; y < 10; y++) {
		Position pv;
		pv.x = this->pos.x;
		pv.y = y;

		if (y != this->pos.y)
			valid.push_back(pv);
	}
}