#include "Soldier.h"

Soldier::Soldier(string name, bool color, int x, int y) :Chess(color, x, y, "soldier", name) {}

void Soldier::findValid(vector<Position>& valid) {
	Position p1, p2, p3;
	vector<Position> pVec;

	p1.x = this->pos.x;

	//red soldier
	if (this->color) {
		p1.y = this->pos.y - 1;

		//over the river
		if (this->pos.y <= 4) {
			p2.x = this->pos.x - 1;
			p2.y = this->pos.y;
			p3.x = this->pos.x + 1;
			p3.y = this->pos.y;

			pVec.push_back(p2);
			pVec.push_back(p3);
		}
	}
	//black soldier
	else {
		p1.y = this->pos.y + 1;

		//over the river
		if (this->pos.y >= 5) {
			p2.x = this->pos.x - 1;
			p2.y = this->pos.y;
			p3.x = this->pos.x + 1;
			p3.y = this->pos.y;

			pVec.push_back(p2);
			pVec.push_back(p3);
		}
	}

	pVec.push_back(p1);

	for (int i = 0; i < pVec.size(); i++) {
		if (pVec[i].x >= 0 && pVec[i].x <= 8 &&
			pVec[i].y >= 0 && pVec[i].y <= 9) {
			valid.push_back(pVec[i]);
		}
	}
}