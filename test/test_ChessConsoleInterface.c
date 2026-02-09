
#ifdef TEST

#include "unity.h"

#include "ChessConsoleInterface.h"
#include "ConsoleBuffer.h"
#include "Board.h"
#include <string.h>
#include <stdlib.h>

void setUp(void)
{
    TEST_ASSERT_EQUAL(0, Console_Init());
}

void tearDown(void)
{
}

void test_ChessConsoleInterface_DrawBoard(void)
{
    TEST_ASSERT_EQUAL(0, Console_DrawBoard());
    Console_Render();
}

//void test_ChessConsoleInterface_Render(void){
//    TEST_ASSERT_EQUAL(0, Console_Render());
//}

void test_ConsoleSquareSet(void){
    ConsoleSquare funnySquare;
    TEST_ASSERT_EQUAL(0, ConsoleSquare_Set(funnySquare, EmptyConsoleSquareBlack));
    TEST_ASSERT_EQUAL_MEMORY(funnySquare, EmptyConsoleSquareBlack, sizeof(ConsoleSquare));
}

void test_ChessConsoleInterface_DrawConsoleSquare(void){
    ConsoleSquare funnySquare;
    memset(funnySquare, 'a', sizeof(ConsoleSquare));
    TEST_ASSERT_EQUAL(0, Console_DrawConsoleSquare(EmptyConsoleSquareBlack, 10, 10));
}

void test_ChessConsoleInterface_DrawSquareByAlgNotation(void){
    TEST_ASSERT_EQUAL(0, Console_DrawSquareByAlgNotation("h8"));
//    Console_Render();
}

void test_ConsoleSquare_WritePiece(void){
    Piece piece;
    piece.type = PIECE_PAWN;
    piece.color = COLOR_BLACK;

    ConsoleSquare consoleSquare;
    TEST_ASSERT_EQUAL(0, ConsoleSquare_WritePiece(consoleSquare, &piece));
    TEST_ASSERT_EQUAL_MEMORY("BP", &consoleSquare[CONSOLE_SQUARE_PIECE_NAME_OFFSET], 2);
}

void test_Console_DrawInfoWindow(void){
    TEST_ASSERT_EQUAL(0, Console_DrawInfoWindow());
}

#endif // TEST
