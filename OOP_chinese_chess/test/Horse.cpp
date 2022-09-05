#include "Horse.h"

Horse::Horse(string name, bool color, int x, int y) :Chess(color, x, y, "horse", name) {}

void Horse::findValid(vector<Position>& valid) {
	Position p1, p2, p3, p4, p5, p6, p7, p8;
	p1.x = this->pos.x - 2;
	p1.y = this->pos.y - 1;
	p2.x = this->pos.x - 1;
	p2.y = this->pos.y - 2;
	p3.x = this->pos.x + 1;
	p3.y = this->pos.y - 2;
	p4.x = this->pos.x + 2;
	p4.y = this->pos.y - 1;
	p5.x = this->pos.x + 2;
	p5.y = this->pos.y + 1;
	p6.x = this->pos.x + 1;
	p6.y = this->pos.y + 2;
	p7.x = this->pos.x - 1;
	p7.y = this->pos.y + 2;
	p8.x = this->pos.x - 2;
	p8.y = this->pos.y + 1;

	vector<Position> pVec;
	pVec.push_back(p1);
	pVec.push_back(p2);
	pVec.push_back(p3);
	pVec.push_back(p4);
	pVec.push_back(p5);
	pVec.push_back(p6);
	pVec.push_back(p7);
	pVec.push_back(p8);

	for (int i = 0; i < pVec.size(); i++) {
		if (pVec[i].x >= 0 && pVec[i].x <= 8 &&
			pVec[i].y >= 0 && pVec[i].y <= 9) {
			valid.push_back(pVec[i]);
		}
	}
}