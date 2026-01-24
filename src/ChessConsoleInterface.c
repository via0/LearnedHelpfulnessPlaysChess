
#include "ChessConsoleInterface.h"

// Coordinates of chessboard on console GUI
#define CONSOLE_BOARD_ORIGIN_X 10
#define CONSOLE_BOARD_ORIGIN_Y 10


ConsoleBuffer consoleBuffer;

int Console_Init(void){
    return ConsoleBuffer_Create(consoleBuffer);
}

int Console_DrawSquare(ConsoleSquare consoleSquare, size_t originX, size_t originY){
    return 0;
}

int Console_DrawBoard(void){
    return 0;
}
