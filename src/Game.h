
#ifndef GAME_H
#define GAME_H

#include "AbstractInputs.h"
#include "Chess.h"

typedef enum {
    GAME_STATE_INIT = 0,
    GAME_STATE_PLAYING_CHESS
} GameStateT;

typedef struct {
    GameStateT     gameState;
    ChessStateT    chessState;
    AbstractInputs inputs;
} Game;

int Game_Create(Game* game);

int Game_Loop(Game* game);
int Game_CheckUserInput(Game* game);
int Game_UpdateGameState(Game* game);

#endif // GAME_H
