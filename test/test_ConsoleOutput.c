
#ifdef TEST

#include "unity.h"

#include "ConsoleOutput.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ConsoleOutput_ConsoleBufferSize(void){
    ConsoleBuffer consoleBuffer;
    TEST_ASSERT_EQUAL(sizeof(consoleBuffer), CONSOLE_WINDOW_HEIGHT * CONSOLE_WINDOW_WIDTH);
    TEST_ASSERT_EQUAL(sizeof(consoleBuffer[0]), CONSOLE_WINDOW_HEIGHT);
}

void test_ConsoleOutput_ConsoleBufferCreate(void){
    ConsoleBuffer consoleBuffer;
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_Create(consoleBuffer));
}

#endif // TEST
