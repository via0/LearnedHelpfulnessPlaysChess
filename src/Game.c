
#include "Game.h"
#include "AbstractInputs.h"
#include "ChessConsoleInterface.h"

int Game_Create(Game* game){
    game->gameState = GAME_STATE_INIT;

    if(AbstractInputs_Clear(&game->inputs)){
        return 1;
    }

    return 0;
}

int Game_Loop(Game* game){
    // Check User Input
    // Process Data
    // Update State
    // Render Output
    if(!Console_Render()){
        return 1;
    }
    return 0;
}

int Game_UpdateGameState(Game* game){
    switch(game->gameState){
        case GAME_STATE_INIT:
            if(AbstractInputs_GetInputJ(&game->inputs)){
                game->gameState = GAME_STATE_PLAYING_CHESS;
            }
            break;
        default:
            break;
    }
    return 0;
}

int Game_CheckUserInput(Game* game){
    return 0;
}
