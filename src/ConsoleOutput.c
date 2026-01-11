
#include "ConsoleOutput.h"
#include <assert.h>
#include <stdio.h>

int ConsoleBuffer_Create(ConsoleBuffer consoleBuffer){
    // Memory should already be allocated
    assert(consoleBuffer != NULL);
    for(int row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        for(int col = 0; col < CONSOLE_WINDOW_WIDTH; col++){
            consoleBuffer[row][col] = '+';
        }
    }
    return 0;
}

void ConsoleBuffer_Print(ConsoleBuffer consoleBuffer){
    for(int row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        printf(consoleBuffer[row]);
    }
}
