#include "GameManager.h"

GameManager::GameManager() {
    this->running = true;
    this->state = "menu";
    this->gameBoard = NULL;
    this->currentColor = true;
    this->currentPick = "";
    this->newGame = false;
}

void GameManager::loadChessImg() {
    //load red chess images
    this->gameBoard->rdKing.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_king.png");
    this->gameBoard->rdAdvisor1.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_advisor.png");
    this->gameBoard->rdAdvisor2.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_advisor.png");
    this->gameBoard->rdChariot1.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_chariot.png");
    this->gameBoard->rdChariot2.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_chariot.png");
    this->gameBoard->rdCannon1.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_cannon.png");
    this->gameBoard->rdCannon2.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_cannon.png");
    this->gameBoard->rdElephant1.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_elephant.png");
    this->gameBoard->rdElephant2.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_elephant.png");
    this->gameBoard->rdHorse1.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_horse.png");
    this->gameBoard->rdHorse2.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_horse.png");
    this->gameBoard->rdSoldier1.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_soldier.png");
    this->gameBoard->rdSoldier2.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_soldier.png");
    this->gameBoard->rdSoldier3.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_soldier.png");
    this->gameBoard->rdSoldier4.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_soldier.png");
    this->gameBoard->rdSoldier5.texture = IMG_LoadTexture(this->gameViewer.renderer, "red_soldier.png");

    //load black chess images
    this->gameBoard->bkKing.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_king.png");
    this->gameBoard->bkAdvisor1.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_advisor.png");
    this->gameBoard->bkAdvisor2.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_advisor.png");
    this->gameBoard->bkChariot1.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_chariot.png");
    this->gameBoard->bkChariot2.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_chariot.png");
    this->gameBoard->bkCannon1.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_cannon.png");
    this->gameBoard->bkCannon2.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_cannon.png");
    this->gameBoard->bkElephant1.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_elephant.png");
    this->gameBoard->bkElephant2.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_elephant.png");
    this->gameBoard->bkHorse1.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_horse.png");
    this->gameBoard->bkHorse2.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_horse.png");
    this->gameBoard->bkSoldier1.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_soldier.png");
    this->gameBoard->bkSoldier2.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_soldier.png");
    this->gameBoard->bkSoldier3.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_soldier.png");
    this->gameBoard->bkSoldier4.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_soldier.png");
    this->gameBoard->bkSoldier5.texture = IMG_LoadTexture(this->gameViewer.renderer, "bk_soldier.png");
}

bool GameManager::initGame() {
    cout << "Init game\n";

    //fail to initialize sdl
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "ERROR: fail to initialize sdl\n";
        return false;
    }
    //fail to create window
    if (!this->gameViewer.window) {
        cout << "ERROR: fail to create window\n";
        return false;
    }
    //fail to create renderer
    if (!this->gameViewer.renderer) {
        cout << "ERROR: fail to create renderer\n";
        return false;
    }
    //fail to create menu texture
    if (!this->gameViewer.MENU_TEXT) {
        cout << "ERROR: fail to create MENU TEXTURE\n";
        return false;
    }
    //fail to create board texture
    if (!this->gameViewer.BOARD_TEXT) {
        cout << "ERROR: fail to create BOARD TEXTURE\n";
        return false;
    }
    //fail to create valid position texture
    if (!this->gameViewer.valid_pos) {
        cout << "ERROR: fail to create valid position texture\n";
        return false;
    }


    SDL_ShowWindow(this->gameViewer.window);

    return true;
}

void GameManager::exitGame() {
    cout << "Exit game\n";
    /*SDL_DestroyTexture();
    SDL_DestroyRenderer();*/
    SDL_DestroyWindow(this->gameViewer.window);
    SDL_Quit();
}

void GameManager::printGame() {
    this->gameViewer.render(this->state, this->gameBoard->chessVec, this->gameBoard->valid, this->currentColor, this->currentColor);
    this->gameViewer.presentScene();
}

void GameManager::gameLoop() {
    if (this->newGame) {
        delete this->gameBoard;
        this->gameBoard = new Board;
        this->loadChessImg();
        this->newGame = false;
        this->currentColor = true;
        this->currentPick = "";
    }

    if (this->state == "game" ||
        this->state == "pick_chess" ||
        this->state == "end") {
        this->checkWinner();
    }
}

void GameManager::checkWinner() {
    if ((!this->gameBoard->rdKing.alive && this->gameBoard->bkKing.alive) ||
        (!this->gameBoard->bkKing.alive && this->gameBoard->rdKing.alive)){
        this->state = "end";
    }
}

void GameManager::eventHandler(SDL_Event* newEvent) {
    if (newEvent->type == SDL_QUIT) {
        this->running = false;
    }
    //detect mouse movement
    else if (newEvent->type == SDL_MOUSEBUTTONDOWN) {
        //already pick a chess
        if (this->state == "pick_chess") {
            //move to valid position
            if (newEvent->button.button == SDL_BUTTON_LEFT &&
                this->gameBoard->checkValidPos(newEvent->button.x, newEvent->button.y)) {
                this->gameBoard->moveChess(this->currentPick, (newEvent->button.x - 25) / 68, (newEvent->button.y - 25) / 68);

                //take turn
                this->currentColor = !this->currentColor;
                this->currentPick = "";
                this->state = "game";
            }

        }

        //in game
        if (this->state == "game" || this->state == "pick_chess") {
            //click home button
            if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.homeButt.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.homeButt.buttonRect.x + this->gameViewer.homeButt.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.homeButt.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.homeButt.buttonRect.y + this->gameViewer.homeButt.buttonRect.h)) {
                this->state = "menu";
                this->gameViewer.blitButtonShadow(3);
                this->gameViewer.presentScene();
            }
            //click surrender button
            else if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.surrButt.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.surrButt.buttonRect.x + this->gameViewer.surrButt.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.surrButt.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.surrButt.buttonRect.y + this->gameViewer.surrButt.buttonRect.h)) {
                this->state = "end";
                this->gameViewer.blitButtonShadow(5);
                this->gameViewer.presentScene();
            }
            //pick a chess
            else if (newEvent->button.button == SDL_BUTTON_LEFT &&
                this->gameBoard->checkPressChess(newEvent->button.x, newEvent->button.y) != "null" &&
                this->gameBoard->getColor(this->gameBoard->checkPressChess(newEvent->button.x, newEvent->button.y)) == this->currentColor) {
                this->gameBoard->valid.clear();

                this->currentPick = this->gameBoard->checkPressChess(newEvent->button.x, newEvent->button.y);
                string type = this->gameBoard->getType(this->currentPick);
                this->gameBoard->getValid(this->currentPick, this->gameBoard->valid);
                int px = 0, py = 0;
                this->gameBoard->getPos(this->currentPick, px, py);
                this->gameBoard->removeOverlapped(this->currentColor, type, px, py, this->gameBoard->valid);

                //print information
                cout << "pick " << this->currentPick << endl;
                cout << "valid position\n";
                for (int i = 0; i < this->gameBoard->valid.size(); i++) {
                    cout << "(" << this->gameBoard->valid[i].x << ", " << this->gameBoard->valid[i].y << ")\n";
                }

                this->state = "pick_chess";
            }
        }
        //at menu
        else if (this->state == "menu") {
            //click start button
            if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.startButt.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.startButt.buttonRect.x + this->gameViewer.startButt.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.startButt.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.startButt.buttonRect.y + this->gameViewer.startButt.buttonRect.h)) {
                this->state = "game";
                this->gameViewer.blitButtonShadow(0);
                this->gameViewer.presentScene();
                this->newGame = true;
            }
            //click read button
            /*else if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.readButt.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.readButt.buttonRect.x + this->gameViewer.readButt.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.readButt.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.readButt.buttonRect.y + this->gameViewer.readButt.buttonRect.h)) {
                this->state = "read";
                this->gameViewer.blitButtonShadow(1);
                this->gameViewer.presentScene();
                this->newGame = true;

                ifstream ifs;
                string fileName;
                cin >> fileName;
                fileName = "C:\\Users\\88696\\Desktop\\台科\\大二下\\物件導向實習\\test\\readfile\\" + fileName;
                ifs.open(fileName);

                if (!ifs.is_open())
                    cout << "failed to open file\n";
                else
                    while (!ifs.eof()) {
                        string command[9];
                        for (int i = 0; i < 9; i++) {
                            ifs >> command[i];

                            if (command[1] == "1,") {
                                this->currentColor = true;
                            }
                            else if (command[1] == "2,") {
                                this->currentColor = false;
                            }
                        }
                    }
            }*/
            //click end button
            else if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.endButt.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.endButt.buttonRect.x + this->gameViewer.endButt.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.endButt.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.endButt.buttonRect.y + this->gameViewer.endButt.buttonRect.h)) {
                this->gameViewer.blitButtonShadow(2);
                this->gameViewer.presentScene();
                this->running = false;
            }
        }
        //game ends
        else if (this->state == "end") {
            //show result
            this->gameViewer.presentScene();

            //click home button
            if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.homeButt.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.homeButt.buttonRect.x + this->gameViewer.homeButt.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.homeButt.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.homeButt.buttonRect.y + this->gameViewer.homeButt.buttonRect.h)) {
                this->state = "menu";
                this->gameViewer.blitButtonShadow(3);
                this->gameViewer.presentScene();
            }
            //click again button
            else if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= this->gameViewer.endGameAct.buttonRect.x &&
                newEvent->button.x <= (this->gameViewer.endGameAct.buttonRect.x + this->gameViewer.endGameAct.buttonRect.w / 2) &&
                newEvent->button.y >= this->gameViewer.endGameAct.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.endGameAct.buttonRect.y + this->gameViewer.endGameAct.buttonRect.h)) {
                this->state = "game";
                this->gameViewer.presentScene();
                this->newGame = true;
            }
            //click end button
            else if (newEvent->button.button == SDL_BUTTON_LEFT &&
                newEvent->button.x >= (this->gameViewer.endGameAct.buttonRect.x + this->gameViewer.endGameAct.buttonRect.w / 2) &&
                newEvent->button.x <= (this->gameViewer.endGameAct.buttonRect.x + this->gameViewer.endGameAct.buttonRect.w) &&
                newEvent->button.y >= this->gameViewer.endGameAct.buttonRect.y &&
                newEvent->button.y <= (this->gameViewer.endGameAct.buttonRect.y + this->gameViewer.endGameAct.buttonRect.h)) {
                this->running = false;
            }
        }
    }
}