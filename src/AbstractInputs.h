
#ifndef ABSTRACTINPUTS_H
#define ABSTRACTINPUTS_H

#include <stdbool.h>

typedef struct{
    bool up    : 1;
    bool down  : 1;
    bool left  : 1;
    bool right : 1;
    bool j     : 1;
    bool k     : 1;
    bool pause : 1;
} AbstractInputs;

int AbstractInputs_Clear(AbstractInputs* inputs);
int AbstractInputs_AreAnyInputsSet(AbstractInputs* inputs);

// Setters and Clearers
int AbstractInputs_SetInputUp(AbstractInputs* inputs);
int AbstractInputs_SetInputDown(AbstractInputs* inputs);
int AbstractInputs_SetInputLeft(AbstractInputs* inputs);
int AbstractInputs_SetInputRight(AbstractInputs* inputs);
int AbstractInputs_SetInputJ(AbstractInputs* inputs);
int AbstractInputs_SetInputK(AbstractInputs* inputs);
int AbstractInputs_SetInputPause(AbstractInputs* inputs);

int AbstractInputs_ClearInputUp(AbstractInputs* inputs);
int AbstractInputs_ClearInputDown(AbstractInputs* inputs);
int AbstractInputs_ClearInputLeft(AbstractInputs* inputs);
int AbstractInputs_ClearInputRight(AbstractInputs* inputs);
int AbstractInputs_ClearInputJ(AbstractInputs* inputs);
int AbstractInputs_ClearInputK(AbstractInputs* inputs);
int AbstractInputs_ClearInputPause(AbstractInputs* inputs);

// Getters
int AbstractInputs_GetInputUp(AbstractInputs* inputs);
int AbstractInputs_GetInputDown(AbstractInputs* inputs);
int AbstractInputs_GetInputLeft(AbstractInputs* inputs);
int AbstractInputs_GetInputRight(AbstractInputs* inputs);
int AbstractInputs_GetInputJ(AbstractInputs* inputs);
int AbstractInputs_GetInputK(AbstractInputs* inputs);
int AbstractInputs_GetInputPause(AbstractInputs* inputs);

#endif // ABSTRACTINPUTS_H
