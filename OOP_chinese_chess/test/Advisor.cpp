#include "Advisor.h"

Advisor::Advisor(string name, bool color, int x, int y) :Chess(color, x, y, "advisor", name) {}

void Advisor::findValid(vector<Position>& valid) {

	Position p_ru;
	p_ru.x = this->pos.x + 1;
	p_ru.y = this->pos.y - 1;

	Position p_lu;
	p_lu.x = this->pos.x - 1;
	p_lu.y = this->pos.y - 1;

	Position p_rd;
	p_rd.x = this->pos.x + 1;
	p_rd.y = this->pos.y + 1;

	Position p_ld;
	p_ld.x = this->pos.x - 1;
	p_ld.y = this->pos.y + 1;

	//left bottom
	if ((this->pos.x == 3 && this->pos.y == 9) ||
		(this->pos.x == 3 && this->pos.y == 2)) {
		valid.push_back(p_ru);
	}
	//right bottom
	else if ((this->pos.x == 5 && this->pos.y == 9)||
		(this->pos.x == 5 && this->pos.y == 2)) {
		valid.push_back(p_lu);
	}
	//left up
	else if ((this->pos.x == 3 && this->pos.y == 0) ||
		(this->pos.x == 3 && this->pos.y == 7)) {
		valid.push_back(p_rd);
	}
	//right up
	else if ((this->pos.x == 5 && this->pos.y == 0) ||
		(this->pos.x == 5 && this->pos.y == 7)) {
		valid.push_back(p_ld);
	}
	//center
	else if ((this->pos.x == 4 && this->pos.y == 1) ||
		(this->pos.x == 4 && this->pos.y == 8)) {
		valid.push_back(p_ru);
		valid.push_back(p_lu);
		valid.push_back(p_rd);
		valid.push_back(p_ld);
	}
}