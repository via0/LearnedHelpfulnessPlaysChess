
#ifdef TEST

#include "unity.h"

#include "ChessConsoleInterface.h"

void setUp(void)
{
    //TEST_ASSERT_EQUAL(0, Console_Init());
}

void tearDown(void)
{
}

void test_ChessConsoleInterface_DrawBoard(void)
{
    TEST_ASSERT_EQUAL(0, Console_DrawBoard());
}

#endif // TEST
