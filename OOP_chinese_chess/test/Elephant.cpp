#include "Elephant.h"

Elephant::Elephant(string name, bool color, int x, int y) :Chess(color, x, y, "elephant", name) {}

void Elephant::findValid(vector<Position>& valid) {
	//bottom
	if (this->pos.y == 4 || this->pos.y == 9) {
		Position p_ru, p_lu;
		p_ru.x = this->pos.x + 2;
		p_ru.y = this->pos.y - 2;
		p_lu.x = this->pos.x - 2;
		p_lu.y = this->pos.y - 2;

		valid.push_back(p_ru);
		valid.push_back(p_lu);
	}
	//top
	else if (this->pos.y == 0 || this->pos.y == 5) {
		Position p_rd, p_ld;
		p_rd.x = this->pos.x + 2;
		p_rd.y = this->pos.y + 2;
		p_ld.x = this->pos.x - 2;
		p_ld.y = this->pos.y + 2;

		valid.push_back(p_rd);
		valid.push_back(p_ld);

	}
	//center
	else if (this->pos.y == 2 || this->pos.y == 7) {
		Position p_ru, p_rd, p_lu, p_ld;
		p_ru.x = this->pos.x + 2;
		p_ru.y = this->pos.y - 2;
		p_lu.x = this->pos.x - 2;
		p_lu.y = this->pos.y - 2;
		p_rd.x = this->pos.x + 2;
		p_rd.y = this->pos.y + 2;
		p_ld.x = this->pos.x - 2;
		p_ld.y = this->pos.y + 2;

		if (this->pos.x == 0) {
			valid.push_back(p_ru);
			valid.push_back(p_rd);
		}
		else if (this->pos.x == 4) {
			valid.push_back(p_ru);
			valid.push_back(p_rd);
			valid.push_back(p_lu);
			valid.push_back(p_ld);
		}
		else if (this->pos.x == 8) {
			valid.push_back(p_lu);
			valid.push_back(p_ld);
		}
	}
}