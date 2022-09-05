#include <iostream>
#include "GameManager.h"

using namespace std;

int main(int argc, char* args[])
{
newGame:

    GameManager game;
    SDL_Event gameEvent;

    //initialize game
    if (!game.initGame()) {
        return -1;
    }

    //enter game loop
    while (game.running) {
        while (SDL_PollEvent(&gameEvent)) {
            game.eventHandler(&gameEvent);
        }          

        game.gameLoop();
        game.printGame();
    }

    //end game
    game.exitGame();
    
    return 0;
}