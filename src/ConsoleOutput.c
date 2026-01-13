
#include "ConsoleOutput.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int ConsoleBuffer_Create(ConsoleBuffer consoleBuffer){
    // Memory should already be allocated
    assert(consoleBuffer != NULL);
    for(size_t row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        for(size_t col = 0; col < CONSOLE_WINDOW_WIDTH; col++){
            consoleBuffer[row][col] = '+';
        }
    }
    return 0;
}

void ConsoleBuffer_Print(ConsoleBuffer consoleBuffer){
    for(size_t row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        for(size_t col = 0; col < CONSOLE_WINDOW_WIDTH; col++){
            printf("%c", consoleBuffer[row][col]);
        }
        printf("\n");
    }
}

int ConsoleBuffer_WriteString(ConsoleBuffer consoleBuffer, size_t startRow, size_t startCol, const char* inString){
    size_t stringLength = 0;
    char validatedString[CONSOLE_WINDOW_WIDTH];

    if(startRow >= CONSOLE_WINDOW_HEIGHT)
        return 1;

    while(*inString != '\0'){

        // Check for input string extending out of bounds
        if((startCol + stringLength) >= CONSOLE_WINDOW_WIDTH)
            return 1;

        validatedString[stringLength++] = *inString++;
    }

    memcpy(&consoleBuffer[startRow][startCol], validatedString, stringLength);
    
    return 0;
}
