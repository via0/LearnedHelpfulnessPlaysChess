
#ifndef CHESSCONSOLEINTERFACE_H
#define CHESSCONSOLEINTERFACE_H

#include "ConsoleBuffer.h"

// these are Squares in the chess sense, not necessarily in the geometric sense
#define CONSOLE_SQUARE_WIDTH  7
#define CONSOLE_SQUARE_HEIGHT 4

typedef char ConsoleSquare[CONSOLE_SQUARE_WIDTH * CONSOLE_SQUARE_HEIGHT];

extern const ConsoleSquare EmptyConsoleSquare;

int Console_Render(void);
int Console_Init(void);
int Console_DrawSquare(const ConsoleSquare consoleSquare, size_t originX, size_t originY);
int Console_DrawBoard(void);

#endif // CHESSCONSOLEINTERFACE_H
