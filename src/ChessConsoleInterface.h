
#ifndef CHESSCONSOLEINTERFACE_H
#define CHESSCONSOLEINTERFACE_H

#include "ConsoleBuffer.h"
#include "Board.h"

// these are Squares in the chess sense, not necessarily in the geometric sense
#define CONSOLE_SQUARE_WIDTH  9
#define CONSOLE_SQUARE_HEIGHT 4

// where we write the piece name in the square
#define PIECE_NAME_OFFSET_X 4
#define PIECE_NAME_OFFSET_Y 2
#define CONSOLE_SQUARE_PIECE_NAME_OFFSET ((PIECE_NAME_OFFSET_Y * CONSOLE_SQUARE_WIDTH) + PIECE_NAME_OFFSET_X)

typedef char ConsoleSquare[CONSOLE_SQUARE_WIDTH * CONSOLE_SQUARE_HEIGHT];

extern const ConsoleSquare EmptyConsoleSquareBlack;
extern const ConsoleSquare EmptyConsoleSquareWhite;

int Console_Render(void);
int Console_Init(void);
int Console_DrawSquareByAlgNotation();
int Console_DrawConsoleSquare(const ConsoleSquare consoleSquare, size_t originX, size_t originY);
int Console_DrawBoard(void);

int ConsoleSquare_Set(ConsoleSquare dest, const ConsoleSquare value);
int ConsoleSquare_WritePiece(ConsoleSquare consoleSquare, Piece* piece);

#endif // CHESSCONSOLEINTERFACE_H
