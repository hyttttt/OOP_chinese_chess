#include "Chess.h"

Chess::Chess() {
	this->type = "";
	this->alive = true;
	this->texture = NULL;
}

Chess::Chess(bool color, int x, int y, string type, string name) {
	this->color = color;
	this->pos.x = x;
	this->pos.y = y;
	this->type = type;
	this->name = name;
	this->alive = true;
	this->texture = NULL;

	this->rect.w = 56;
	this->rect.h = 56;
	this->rect.x = 25 + 68 * x;
	this->rect.y = 25 + 68 * y;
}

void Chess::move(int x, int y, vector<Position>& valid) {
	this->pos.x = x;
	this->pos.y = y;
	this->rect.x = 25 + 68 * x;
	this->rect.y = 25 + 68 * y;
}

Chess& Chess::operator=(const Chess& c) {
	this->color = c.color;
	this->name = c.name;
	this->pos.x = c.pos.x;
	this->pos.y = c.pos.y;
	this->rect = c.rect;
	
	return *this;
}