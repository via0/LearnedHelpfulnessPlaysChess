
#include "ChessConsoleInterface.h"
#include "Board.h"

// Coordinates of chessboard on console GUI
#define CONSOLE_BOARD_ORIGIN_X 10
#define CONSOLE_BOARD_ORIGIN_Y 10

const ConsoleSquare EmptyConsoleSquare =
                "+------" 
                "|......" 
                "|..Wq.." 
                "|......";

ConsoleBuffer consoleBuffer;
Board board;

int Console_Init(void){
    return ConsoleBuffer_Create(consoleBuffer);
}

int Console_Render(void){
    return ConsoleBuffer_Print(consoleBuffer);
}

int Console_DrawSquare(const ConsoleSquare consoleSquare, size_t originX, size_t originY){
    return ConsoleBuffer_DrawRectangle(consoleBuffer, originY, originX, (const char*) consoleSquare, CONSOLE_SQUARE_WIDTH, CONSOLE_SQUARE_HEIGHT);
}

int Console_DrawBoard(void){

    return 0;
}
