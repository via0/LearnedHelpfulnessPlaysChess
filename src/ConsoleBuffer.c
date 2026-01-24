
#include "ConsoleBuffer.h"
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

int ConsoleBuffer_Print(ConsoleBuffer consoleBuffer){
    for(size_t row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        for(size_t col = 0; col < CONSOLE_WINDOW_WIDTH; col++){
            printf("%c", consoleBuffer[row][col]);
        }
        printf("\n");
    }

    return 0;
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

int ConsoleBuffer_DrawRectangle(ConsoleBuffer consoleBuffer, size_t startRow, size_t startCol, const char* inSquare, size_t width, size_t height){

    for(size_t row = startRow; row < startRow + height; row++){
        for(size_t col = startCol; col < startCol + width; col++){
            if(ConsoleBuffer_DrawChar(consoleBuffer, row, col,
                        inSquare[((row - startRow) * width) + (col - startCol)]) != 0)
                return 1;
        }
    }
    return 0;
}

int ConsoleBuffer_DrawChar(ConsoleBuffer consoleBuffer, size_t row, size_t col, const char inChar){
    if(row >= CONSOLE_WINDOW_HEIGHT) return 1;
    if(col >= CONSOLE_WINDOW_WIDTH) return 1;

    consoleBuffer[row][col] = inChar;
    return 0;
}
