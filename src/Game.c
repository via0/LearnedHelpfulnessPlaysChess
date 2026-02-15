
#include "Game.h"

int Game_Create(Game* game){
    game->state = GAME_STATE_INIT;

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
    return 0;
}
