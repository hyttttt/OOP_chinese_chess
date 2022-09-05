#include "King.h"

King::King(string name, bool color, int x, int y) :Chess(color, x, y, "king", name) {}

void King::findValid(vector<Position>& valid) {
	Position pu, pd, pl, pr;
	vector<Position> pVec;

	pu.x = this->pos.x;
	pu.y = this->pos.y - 1;
	pd.x = this->pos.x;
	pd.y = this->pos.y + 1;
	pl.x = this->pos.x - 1;
	pl.y = this->pos.y;
	pr.x = this->pos.x + 1;
	pr.y = this->pos.y;

	pVec.push_back(pu);
	pVec.push_back(pd);
	pVec.push_back(pl);
	pVec.push_back(pr);

	for (int i = 0; i < pVec.size(); i++) {
		if ((pVec[i].x >= 3 && pVec[i].x <= 5) &&
			((pVec[i].y >= 7 && pVec[i].y <= 9) || (pVec[i].y >= 0 && pVec[i].y <= 2))) {
			valid.push_back(pVec[i]);
		}
	}
}