
#ifdef TEST

#include "unity.h"

#include "ChessConsoleInterface.h"
#include "ConsoleBuffer.h"
#include <string.h>
#include <stdlib.h>

void setUp(void)
{
    TEST_ASSERT_EQUAL(0, Console_Init());
}

void tearDown(void)
{
}

//void test_ChessConsoleInterface_DrawBoard(void)
//{
//    TEST_ASSERT_EQUAL(0, Console_DrawBoard());
//}

//void test_ChessConsoleInterface_Render(void){
//    TEST_ASSERT_EQUAL(0, Console_Render());
//}

void test_ChessConsoleInterface_DrawSquare(void){
    ConsoleSquare funnySquare;
    memset(funnySquare, 'a', sizeof(ConsoleSquare));
    TEST_ASSERT_EQUAL(0, Console_DrawSquare(EmptyConsoleSquare, 10, 10));
    TEST_ASSERT_EQUAL(0, Console_Render());
}

void test_ChessConsoleInterface_DrawBoard(void){
    ConsoleSquare funnyBoard[64];
    for(int i = 0; i < 64; i++)
        memcpy(funnyBoard[i], EmptyConsoleSquare, sizeof(ConsoleSquare));
}

#endif // TEST
