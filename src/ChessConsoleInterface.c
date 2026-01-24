
#include "ChessConsoleInterface.h"

ConsoleBuffer consoleBuffer;

int Console_Init(void){
    return ConsoleBuffer_Create(consoleBuffer);
}

int Console_DrawBoard(void){
    return 0;
}
