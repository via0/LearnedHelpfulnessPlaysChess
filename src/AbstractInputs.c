
#include "AbstractInputs.h"
#include <string.h>
#include <stdint.h>

int AbstractInputs_Clear(AbstractInputs* inputs){
    memset((uint8_t*) inputs, 0, sizeof(AbstractInputs));
    return 0;
}

int AbstractInputs_AreAnyInputsSet(AbstractInputs* inputs){
    return (inputs->up
        || inputs->down
        || inputs->left
        || inputs->right
        || inputs->j
        || inputs->k
        || inputs->pause);
}

int AbstractInputs_SetInputUp(AbstractInputs* inputs){
    inputs->up = 1;
    return 0;
}

int AbstractInputs_SetInputDown(AbstractInputs* inputs){
    inputs->down = 1;
    return 0;
}

int AbstractInputs_SetInputLeft(AbstractInputs* inputs){
    inputs->left = 1;
    return 0;
}

int AbstractInputs_SetInputRight(AbstractInputs* inputs){
    inputs->right = 1;
    return 0;
}

int AbstractInputs_SetInputJ(AbstractInputs* inputs){
    inputs->j = 1;
    return 0;
}

int AbstractInputs_SetInputK(AbstractInputs* inputs){
    inputs->k = 1;
    return 0;
}

int AbstractInputs_SetInputPause(AbstractInputs* inputs){
    inputs->pause = 1;
    return 0;
}

int AbstractInputs_ClearInputUp(AbstractInputs* inputs){
    inputs->up = 0;
    return 0;
}

int AbstractInputs_ClearInputDown(AbstractInputs* inputs){
    inputs->down = 0;
    return 0;
}

int AbstractInputs_ClearInputLeft(AbstractInputs* inputs){
    inputs->left = 0;
    return 0;
}

int AbstractInputs_ClearInputRight(AbstractInputs* inputs){
    inputs->right = 0;
    return 0;
}

int AbstractInputs_ClearInputJ(AbstractInputs* inputs){
    inputs->j = 0;
    return 0;
}

int AbstractInputs_ClearInputK(AbstractInputs* inputs){
    inputs->k = 0;
    return 0;
}

int AbstractInputs_ClearInputPause(AbstractInputs* inputs){
    inputs->pause = 0;
    return 0;
}

int AbstractInputs_GetInputUp(AbstractInputs* inputs){
    return inputs->up;
}

int AbstractInputs_GetInputDown(AbstractInputs* inputs){
    return inputs->down;
}

int AbstractInputs_GetInputLeft(AbstractInputs* inputs){
    return inputs->left;
}

int AbstractInputs_GetInputRight(AbstractInputs* inputs){
    return inputs->right;
}

int AbstractInputs_GetInputJ(AbstractInputs* inputs){
    return inputs->j;
}

int AbstractInputs_GetInputK(AbstractInputs* inputs){
    return inputs->k;
}

int AbstractInputs_GetInputPause(AbstractInputs* inputs){
    return inputs->pause;
}
