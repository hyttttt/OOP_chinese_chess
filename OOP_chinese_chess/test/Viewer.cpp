#include "Viewer.h"

Viewer::Viewer() {
	this->WINDOW_WIDTH = 960;
	this->WINDOW_HEIGHT = 720;

	this->window = SDL_CreateWindow("Chinese chess",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		this->WINDOW_WIDTH, this->WINDOW_HEIGHT,
		SDL_WINDOW_HIDDEN);

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

	this->startButt.buttonRect.x = 320;		this->startButt.buttonRect.y = 320;
	this->startButt.texture = IMG_LoadTexture(this->renderer, "start_button.jpg");

	this->readButt.buttonRect.x = 320;		this->readButt.buttonRect.y = 420;
	this->readButt.texture = IMG_LoadTexture(this->renderer, "read_button.jpg");

	this->endButt.buttonRect.x = 320;		this->endButt.buttonRect.y = 520;
	this->endButt.texture = IMG_LoadTexture(this->renderer, "end_button.jpg");

	this->homeButt.buttonRect.x = 860;		this->homeButt.buttonRect.y = 620;
	this->homeButt.buttonRect.w = 80;		this->homeButt.buttonRect.h = 80;
	this->homeButt.texture = IMG_LoadTexture(this->renderer, "home_button.jpg");

	this->endGameAct.buttonRect.x = 665;	this->endGameAct.buttonRect.y = 90;	
	this->endGameAct.buttonRect.w = 280;		this->endGameAct.buttonRect.h = 70;
	this->endGameAct.texture = IMG_LoadTexture(this->renderer, "endGame_act.jpg");

	this->surrButt.buttonRect.x = 770;		this->surrButt.buttonRect.y = 620;
	this->surrButt.buttonRect.w = 80;		this->surrButt.buttonRect.h = 80;
	this->surrButt.texture = IMG_LoadTexture(this->renderer, "surrender_button.jpg");

	this->BOARD_TEXT = IMG_LoadTexture(this->renderer, "background.jpg");
	this->MENU_TEXT = IMG_LoadTexture(this->renderer, "menu.jpg");
	this->valid_pos = IMG_LoadTexture(this->renderer, "valid_pos.png");
	this->curr_red = IMG_LoadTexture(this->renderer, "current_red.jpg");
	this->curr_bk = IMG_LoadTexture(this->renderer, "current_bk.jpg");
	this->win_red = IMG_LoadTexture(this->renderer, "win_red.jpg");
	this->win_bk = IMG_LoadTexture(this->renderer, "win_bk.jpg");
}

void Viewer::presentScene() {
	SDL_RenderPresent(this->renderer);
	SDL_Delay(100);
}

void Viewer::blitBackground(SDL_Texture* texture) {
	SDL_Rect dest;

	dest.x = 0;
	dest.y = 0;
	dest.w = this->WINDOW_WIDTH;
	dest.h = this->WINDOW_HEIGHT;

	SDL_RenderCopy(this->renderer, texture, NULL, &dest);
}

void Viewer::blitChess(SDL_Texture* texture, SDL_Rect rect) {
	SDL_RenderCopy(this->renderer, texture, NULL, &rect);
}

void Viewer::blitButton(int code) {
	//start button
	if (code == 0) {
		SDL_RenderCopy(this->renderer, this->startButt.texture, NULL, &(this->startButt.buttonRect));
	}
	//read button
	else if (code == 1) {
		SDL_RenderCopy(this->renderer, this->readButt.texture, NULL, &(this->readButt.buttonRect));
	}
	//end button
	else if (code == 2) {
		SDL_RenderCopy(this->renderer, this->endButt.texture, NULL, &(this->endButt.buttonRect));
	}
	//home button
	else if (code == 3) {
		SDL_RenderCopy(this->renderer, this->homeButt.texture, NULL, &(this->homeButt.buttonRect));
	}
	//end game action
	else if (code == 4) {
		SDL_RenderCopy(this->renderer, this->endGameAct.texture, NULL, &(this->endGameAct.buttonRect));
	}
	//surrender button
	else if (code == 5) {
		SDL_RenderCopy(this->renderer, this->surrButt.texture, NULL, &(this->surrButt.buttonRect));
	}
}

void Viewer::blitButtonShadow(int code) {
	SDL_Rect dest;

	//start button
	if (code == 0) {
		dest = this->startButt.buttonRect;
	}
	//read button
	else if (code == 1) {
		dest = this->readButt.buttonRect;
	}
	//end button
	else if (code == 2) {
		dest = this->endButt.buttonRect;
	}
	//home button
	else if (code == 3) {
		dest = this->homeButt.buttonRect;
		dest.x += 5;
		dest.y += 5;
		dest.w -= 10;
		dest.h -= 10;
	}
	//surrender button
	else if (code == 5) {
		dest = this->surrButt.buttonRect;
		dest.x += 5;
		dest.y += 5;
		dest.w -= 10;
		dest.h -= 10;
	}

	SDL_SetRenderDrawColor(this->renderer, 156, 114, 94, 125);
	SDL_RenderFillRect(this->renderer, &dest);
}

void Viewer::blitValidPos(int x, int y) {
	SDL_Rect rect;

	rect.w = 56;
	rect.h = 56;
	rect.x = 25 + 68 * x;
	rect.y = 25 + 68 * y;

	SDL_RenderCopy(this->renderer, this->valid_pos, NULL, &rect);
}

void Viewer::blitCurrentColor(bool curr) {
	SDL_Rect rect;

	rect.w = 280;
	rect.h = 70;
	rect.x = 665;
	rect.y = 15;

	if(curr)
		SDL_RenderCopy(this->renderer, this->curr_red, NULL, &rect);
	else
		SDL_RenderCopy(this->renderer, this->curr_bk, NULL, &rect);
}

void Viewer::blitResult(bool currColor) {
	SDL_Rect rect;

	rect.w = 280;
	rect.h = 70;
	rect.x = 665;
	rect.y = 15;

	if (!currColor)
		SDL_RenderCopy(this->renderer, this->win_red, NULL, &rect);
	else
		SDL_RenderCopy(this->renderer, this->win_bk, NULL, &rect);
}

void Viewer::renderBoard(vector<Chess*>& chessVec) {
	for (int i = 0; i < chessVec.size(); i++) {
		if (chessVec[i]->alive) {
			this->blitChess(chessVec[i]->texture, chessVec[i]->rect);
		}
	}
}

void Viewer::render(string state, vector<Chess*>& chessVec, vector<Position>& valid, bool curr, bool currColor) {
	if (state == "game") {
		this->blitBackground(this->BOARD_TEXT);
		this->blitButton(3); //home button
		this->blitButton(5); //surrender button
		this->blitCurrentColor(curr);
		this->renderBoard(chessVec);
	}
	else if (state == "menu") {
		this->blitBackground(this->MENU_TEXT);
		this->blitButton(0); //start button
		this->blitButton(1); //read button
		this->blitButton(2); //end button
	}
	else if (state == "pick_chess") {
		this->blitBackground(this->BOARD_TEXT);
		this->blitButton(3); //home button
		this->blitButton(5); //surrender button
		this->blitCurrentColor(curr);
		this->renderBoard(chessVec);

		for (int i = 0; i < valid.size(); i++) {
			this->blitValidPos(valid[i].x, valid[i].y);
		}
	}
	else if (state == "end") {
		this->blitBackground(this->BOARD_TEXT);
		this->blitButton(3); //home button
		this->blitButton(4); //end game action
		this->blitButton(5); //surrender button
		this->renderBoard(chessVec);
		this->blitResult(currColor);
	}
	this->presentScene();
}