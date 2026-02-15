
#ifndef GAME_H
#define GAME_H

typedef enum {
    GAME_STATE_INIT = 0
} GameStateT;

typedef struct {
    GameStateT state;
} Game;

int Game_Create(Game* game);

int Game_Loop(Game* game);

#endif // GAME_H
