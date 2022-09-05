#include "Board.h"

Board::Board() {
	//red chess
	King rdK("rdKing", true, 4, 9);
	this->rdKing = rdK;
	this->chess2dArr[9][4] = &(this->rdKing);

	Advisor rdAd1("rdAdvisor1", true, 3, 9);
	this->rdAdvisor1 = rdAd1;
	this->chess2dArr[9][3] = &(this->rdAdvisor1);
	Advisor rdAd2("rdAdvisor2", true, 5, 9);
	this->rdAdvisor2 = rdAd2;
	this->chess2dArr[9][5] = &(this->rdAdvisor2);

	Chariot rdCh1("rdChariot1", true, 0, 9);
	this->rdChariot1 = rdCh1;
	this->chess2dArr[9][0] = &(this->rdChariot1);
	Chariot rdCh2("rdChariot2", true, 8, 9);
	this->rdChariot2 = rdCh2;
	this->chess2dArr[9][8] = &(this->rdChariot2);

	Cannon rdCan1("rdCannon1", true, 1, 7);
	this->rdCannon1 = rdCan1;
	this->chess2dArr[7][1] = &(this->rdCannon1);
	Cannon rdCan2("rdCannon2", true, 7, 7);
	this->rdCannon2 = rdCan2;
	this->chess2dArr[7][7] = &(this->rdCannon2);

	Elephant rdEle1("rdElephant1", true, 2, 9);
	this->rdElephant1 = rdEle1;
	this->chess2dArr[9][2] = &(this->rdElephant1);
	Elephant rdEle2("rdElephant2", true, 6, 9);
	this->rdElephant2 = rdEle2;
	this->chess2dArr[9][6] = &(this->rdElephant2);

	Horse rdHor1("rdHorse1", true, 1, 9);
	this->rdHorse1 = rdHor1;
	this->chess2dArr[9][1] = &(this->rdHorse1);
	Horse rdHor2("rdHorse2", true, 7, 9);
	this->rdHorse2 = rdHor2;
	this->chess2dArr[9][7] = &(this->rdHorse2);

	Soldier rdSol1("rdSoldier1", true, 0, 6);
	this->rdSoldier1 = rdSol1;
	this->chess2dArr[6][0] = &(this->rdSoldier1);
	Soldier rdSol2("rdSoldier2", true, 2, 6);
	this->rdSoldier2 = rdSol2;
	this->chess2dArr[6][2] = &(this->rdSoldier2);
	Soldier rdSol3("rdSoldier3", true, 4, 6);
	this->rdSoldier3 = rdSol3;
	this->chess2dArr[6][4] = &(this->rdSoldier3);
	Soldier rdSol4("rdSoldier4", true, 6, 6);
	this->rdSoldier4 = rdSol4;
	this->chess2dArr[6][6] = &(this->rdSoldier4);
	Soldier rdSol5("rdSoldier5", true, 8, 6);
	this->rdSoldier5 = rdSol5;
	this->chess2dArr[6][8] = &(this->rdSoldier5);

	//black chess
	King bkK("bkKing", false, 4, 0);
	this->bkKing = bkK;
	this->chess2dArr[0][4] = &(this->bkKing);

	Advisor bkAd1("bkAdvisor1", false, 3, 0);
	this->bkAdvisor1 = bkAd1;
	this->chess2dArr[0][3] = &(this->bkAdvisor1);
	Advisor bkAd2("bkAdvisor2", false, 5, 0);
	this->bkAdvisor2 = bkAd2;
	this->chess2dArr[0][5] = &(this->bkAdvisor2);

	Chariot bkCh1("bkChariot1", false, 0, 0);
	this->bkChariot1 = bkCh1;
	this->chess2dArr[0][0] = &(this->bkChariot1);
	Chariot bkCh2("bkChariot2", false, 8, 0);
	this->bkChariot2 = bkCh2;
	this->chess2dArr[0][8] = &(this->bkChariot2);

	Cannon bkCan1("bkCannon1", false, 1, 2);
	this->bkCannon1 = bkCan1;
	this->chess2dArr[2][1] = &(this->bkCannon1);
	Cannon bkCan2("bkCannon2", false, 7, 2);
	this->bkCannon2 = bkCan2;
	this->chess2dArr[2][7] = &(this->bkCannon2);

	Elephant bkEle1("bkElephant1", false, 2, 0);
	this->bkElephant1 = bkEle1;
	this->chess2dArr[0][2] = &(this->bkElephant1);
	Elephant bkEle2("bkElephant2", false, 6, 0);
	this->bkElephant2 = bkEle2;
	this->chess2dArr[0][6] = &(this->bkElephant2);

	Horse bkHor1("bkHorse1", false, 1, 0);
	this->bkHorse1 = bkHor1;
	this->chess2dArr[0][1] = &(this->bkHorse1);
	Horse bkHor2("bkHorse2", false, 7, 0);
	this->bkHorse2 = bkHor2;
	this->chess2dArr[0][7] = &(this->bkHorse2);

	Soldier bkSol1("bkSoldier1", false, 0, 3);
	this->bkSoldier1 = bkSol1;
	this->chess2dArr[3][0] = &(this->bkSoldier1);
	Soldier bkSol2("bkSoldier2", false, 2, 3);
	this->bkSoldier2 = bkSol2;
	this->chess2dArr[3][2] = &(this->bkSoldier2);
	Soldier bkSol3("bkSoldier3", false, 4, 3);
	this->bkSoldier3 = bkSol3;
	this->chess2dArr[3][4] = &(this->bkSoldier3);
	Soldier bkSol4("bkSoldier4", false, 6, 3);
	this->bkSoldier4 = bkSol4;
	this->chess2dArr[3][6] = &(this->bkSoldier4);
	Soldier bkSol5("bkSoldier5", false, 8, 3);
	this->bkSoldier5 = bkSol5;
	this->chess2dArr[3][8] = &(this->bkSoldier5);

	this->chessVec.push_back(&rdKing);
	this->chessVec.push_back(&rdAdvisor1);
	this->chessVec.push_back(&rdAdvisor2);
	this->chessVec.push_back(&rdChariot1);
	this->chessVec.push_back(&rdChariot2);
	this->chessVec.push_back(&rdCannon1);
	this->chessVec.push_back(&rdCannon2);
	this->chessVec.push_back(&rdElephant1);
	this->chessVec.push_back(&rdElephant2);
	this->chessVec.push_back(&rdHorse1);
	this->chessVec.push_back(&rdHorse2);
	this->chessVec.push_back(&rdSoldier1);
	this->chessVec.push_back(&rdSoldier2);
	this->chessVec.push_back(&rdSoldier3);
	this->chessVec.push_back(&rdSoldier4);
	this->chessVec.push_back(&rdSoldier5);

	this->chessVec.push_back(&bkKing);
	this->chessVec.push_back(&bkAdvisor1);
	this->chessVec.push_back(&bkAdvisor2);
	this->chessVec.push_back(&bkChariot1);
	this->chessVec.push_back(&bkChariot2);
	this->chessVec.push_back(&bkCannon1);
	this->chessVec.push_back(&bkCannon2);
	this->chessVec.push_back(&bkElephant1);
	this->chessVec.push_back(&bkElephant2);
	this->chessVec.push_back(&bkHorse1);
	this->chessVec.push_back(&bkHorse2);
	this->chessVec.push_back(&bkSoldier1);
	this->chessVec.push_back(&bkSoldier2);
	this->chessVec.push_back(&bkSoldier3);
	this->chessVec.push_back(&bkSoldier4);
	this->chessVec.push_back(&bkSoldier5);
}

void Board::getValid(string name, vector<Position>& valid) {
	for (int i = 0; i < this->chessVec.size(); i++) {
		if (name == this->chessVec[i]->name) {
			this->chessVec[i]->findValid(valid);
			break;
		}
	}
}

bool Board::getColor(string name) {
	if (name.find("rd") != string::npos)
		return true;
	else
		return false;
}

string Board::getType(string name) {
	if (name.find("King") != string::npos) {
		return "king";
	}
	else if (name.find("Advisor") != string::npos) {
		return "advisor";
	}
	else if (name.find("Chariot") != string::npos) {
		return "chariot";
	}
	else if (name.find("Cannon") != string::npos) {
		return "cannon";
	}
	else if (name.find("Elephant") != string::npos) {
		return "elephant";
	}
	else if (name.find("Horse") != string::npos) {
		return "horse";
	}
	else if (name.find("Soldier") != string::npos) {
		return "soldier";
	}
	else {
		return "null";
	}
}

void Board::getPos(string name, int& x, int& y) {
	for (int i = 0; i < this->chessVec.size(); i++) {
		if (name == this->chessVec[i]->name) {
			x = this->chessVec[i]->pos.x;
			y = this->chessVec[i]->pos.y;
			break;
		}
	}
}

void Board::removeOverlapped(bool color, string type, int x, int y, vector<Position>& valid) {
	vector<Position> result;

	if (type == "chariot") {
		//left
		for (int i = x - 1; i >= 0; i--) {
			if (this->chess2dArr[y][i] == NULL) {
				Position p;
				p.x = i;
				p.y = y;

				result.push_back(p);
			}
			else if (this->chess2dArr[y][i]->color != color) {
				Position p;
				p.x = i;
				p.y = y;

				result.push_back(p);
				break;
			}
			else {
				break;
			}
		}

		//right
		for (int i = x + 1; i <= 8; i++) {
			if (this->chess2dArr[y][i] == NULL) {
				Position p;
				p.x = i;
				p.y = y;

				result.push_back(p);
			}
			else if (this->chess2dArr[y][i]->color != color) {
				Position p;
				p.x = i;
				p.y = y;

				result.push_back(p);
				break;
			}
			else {
				break;
			}
		}

		//up
		for (int i = y - 1; i >= 0; i--) {
			if (this->chess2dArr[i][x] == NULL) {
				Position p;
				p.x = x;
				p.y = i;

				result.push_back(p);
			}
			else if (this->chess2dArr[i][x]->color != color) {
				Position p;
				p.x = x;
				p.y = i;

				result.push_back(p);
				break;
			}
			else {
				break;
			}
		}

		//down
		for (int i = y + 1; i <= 9; i++) {
			if (this->chess2dArr[i][x] == NULL) {
				Position p;
				p.x = x;
				p.y = i;

				result.push_back(p);
			}
			else if (this->chess2dArr[i][x]->color != color) {
				Position p;
				p.x = x;
				p.y = i;

				result.push_back(p);
				break;
			}
			else {
				break;
			}
		}
	}
	else if (type == "cannon") {
		//left
		for (int i = x - 1; i >= 0; i--) {
			if (this->chess2dArr[y][i] == NULL) {
				Position p;
				p.x = i;
				p.y = y;

				result.push_back(p);
			}
			else {
				for (int j = i - 1; j >= 0; j--) {
					if (this->chess2dArr[y][j] != NULL&&
						this->chess2dArr[y][j]->color != color) {
						Position p;
						p.x = j;
						p.y = y;

						result.push_back(p);
						break;
					}
				}
				break;
			}
		}

		//right
		for (int i = x + 1; i <= 8; i++) {
			if (this->chess2dArr[y][i] == NULL) {
				Position p;
				p.x = i;
				p.y = y;

				result.push_back(p);
			}
			else {
				for (int j = i + 1; j <= 8; j++) {
					if (this->chess2dArr[y][j] != NULL &&
						this->chess2dArr[y][j]->color != color) {
						Position p;
						p.x = j;
						p.y = y;

						result.push_back(p);
						break;
					}
				}
				break;
			}
		}

		//up
		for (int i = y - 1; i >= 0; i--) {
			if (this->chess2dArr[i][x] == NULL) {
				Position p;
				p.x = x;
				p.y = i;

				result.push_back(p);
			}
			else {
				for (int j = i - 1; j >= 0; j--) {
					if (this->chess2dArr[j][x] != NULL &&
						this->chess2dArr[j][x]->color != color) {
						Position p;
						p.x = x;
						p.y = j;

						result.push_back(p);
						break;
					}
				}
				break;
			}
		}

		//down
		for (int i = y + 1; i <= 9; i++) {
			if (this->chess2dArr[i][x] == NULL) {
				Position p;
				p.x = x;
				p.y = i;

				result.push_back(p);
			}
			else {
				for (int j = i + 1; j <= 9; j++) {
					if (this->chess2dArr[j][x] != NULL &&
						this->chess2dArr[j][x]->color != color) {
						Position p;
						p.x = x;
						p.y = j;

						result.push_back(p);
						break;
					}
				}
				break;
			}
		}
	}
	else {
		//王不見王
		if (type == "king") {
			//red king
			if (color) {
				for (int j = y - 1; j >= 0; j--) {
					if (this->chess2dArr[j][x] != NULL) {
						if (this->chess2dArr[j][x]->name == "bkKing") {
							Position p;
							p.x = x;
							p.y = j;

							result.push_back(p);
						}
						
						break;
					}
				}
			}
			//black king
			else {
				for (int j = y + 1; j <= 9; j++) {
					if (this->chess2dArr[j][x] != NULL) {
						if (this->chess2dArr[j][x]->name == "rdKing") {
							Position p;
							p.x = x;
							p.y = j;

							result.push_back(p);
						}

						break;
					}
				}
			}
		}

		for (int i = 0; i < valid.size(); i++) {
			bool ok = true;

			//拐馬腳
			if ((type == "horse") &&
				((valid[i].x == x - 2 && this->chess2dArr[y][x - 1] != NULL) ||
				(valid[i].x == x + 2 && this->chess2dArr[y][x + 1] != NULL) ||
				(valid[i].y == y - 2 && this->chess2dArr[y - 1][x] != NULL) ||
				(valid[i].y == y + 2 && this->chess2dArr[y + 1][x] != NULL))) {
				continue;
			}
			//塞象眼
			else if ((type == "elephant") &&
				((valid[i].x == x - 2 && valid[i].y == y - 2 && this->chess2dArr[y - 1][x - 1] != NULL) ||
				(valid[i].x == x - 2 && valid[i].y == y + 2 && this->chess2dArr[y + 1][x - 1] != NULL) || 
				(valid[i].x == x + 2 && valid[i].y == y - 2 && this->chess2dArr[y - 1][x + 1] != NULL) || 
				(valid[i].x == x + 2 && valid[i].y == y + 2 && this->chess2dArr[y + 1][x + 1] != NULL))) {
				continue;
			}

			//remove position with the same color chess on it
			for (int j = 0; j < this->chessVec.size(); j++) {
				if (this->chessVec[j]->pos.x == valid[i].x &&
					this->chessVec[j]->pos.y == valid[i].y &&
					this->chessVec[j]->color == color &&
					this->chessVec[j]->alive) {
					ok = false;
					break;
				}
			}

			if (ok) {
				result.push_back(valid[i]);
			}
		}
	}
	

	valid = result;
}

string Board::checkPressChess(int x, int y) {
	for (int i = 0; i < this->chessVec.size(); i++) {
		if (this->chessVec[i]->alive &&
			x >= this->chessVec[i]->rect.x &&
			x <= this->chessVec[i]->rect.x + this->chessVec[i]->rect.w &&
			y >= this->chessVec[i]->rect.y &&
			y <= this->chessVec[i]->rect.y + this->chessVec[i]->rect.h) {
			return this->chessVec[i]->name;
		}
	}

	return "null";
}

bool Board::checkValidPos(int x, int y) {
	x = (x - 25) / 68;
	y = (y - 25) / 68;

	cout << "mouse at (" << x << ", " << y << ")" << endl;

	for (int i = 0; i < this->valid.size(); i++) {
		if (x == valid[i].x && y == valid[i].y) {
			return true;
		}
	}

	return false;
}

void Board::moveChess(string name, int destX, int destY) {
	for (int i = 0; i < this->chessVec.size(); i++) {
		if (name == this->chessVec[i]->name) {
			//print information
			cout << "from (" << this->chessVec[i]->pos.x << ", " << this->chessVec[i]->pos.y << ") "
				<< "move to (" << destX << ", " << destY << ")\n";

			//eat chess
			for (int j = 0; j < this->chessVec.size(); j++) {
				if (this->chessVec[j]->alive &&
					destX == this->chessVec[j]->pos.x &&
					destY == this->chessVec[j]->pos.y) {
					cout << this->chessVec[i]->name << " eat " << this->chessVec[j]->name << endl;

					int eatX = this->chessVec[j]->pos.x, eatY = this->chessVec[j]->pos.y;
					this->chess2dArr[eatY][eatX] = NULL;
					this->chessVec[j]->alive = false;
					
					break;
				}
			}

			//move in 2d array
			this->chess2dArr[destY][destX] = this->chess2dArr[this->chessVec[i]->pos.y][this->chessVec[i]->pos.x];
			this->chess2dArr[this->chessVec[i]->pos.y][this->chessVec[i]->pos.x] = NULL;

			//move in vector
			this->chessVec[i]->pos.x = destX;
			this->chessVec[i]->pos.y = destY;	
			this->chessVec[i]->rect.x = 25 + destX * 68;
			this->chessVec[i]->rect.y = 25 + destY * 68;
		}
	}
}