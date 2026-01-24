
#ifdef TEST

#include "unity.h"

#include "ConsoleOutput.h"

ConsoleBuffer consoleBuffer;

void setUp(void)
{
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_Create(consoleBuffer));
}

void tearDown(void)
{
}

void test_ConsoleOutput_ConsoleBufferSize(void){
    TEST_ASSERT_EQUAL(sizeof(consoleBuffer), CONSOLE_WINDOW_HEIGHT * CONSOLE_WINDOW_WIDTH);
    TEST_ASSERT_EQUAL(sizeof(consoleBuffer[0]), CONSOLE_WINDOW_WIDTH);
}

void test_ConsoleOutput_WriteString_To_Buffer(){
    const char message[] = "My Name Jeff";
    size_t length = strlen(message);
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_WriteString(consoleBuffer, 0, 0, message));
    TEST_ASSERT_EQUAL_MEMORY("My Name Jeff", &consoleBuffer[0][0], length);
}

void test_ConsoleOutput_WriteString_Length_Too_Long(){
    const char message[] = "21";
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_WriteString(consoleBuffer, 0, CONSOLE_WINDOW_WIDTH - 1, message));
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_WriteString(consoleBuffer, 0, CONSOLE_WINDOW_WIDTH - 1, "2"));
}

void test_ConsoleOutput_WriteString_Start_Row_Negative(){
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_WriteString(consoleBuffer, -1, 0, "annoying orange"));
}

void test_ConsoleOutput_WriteString_Start_Col_Negative(){
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_WriteString(consoleBuffer, 0, -1, "Epic"));
}

void test_ConsoleOutput_WriteString_Start_Row_Too_High(){
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_WriteString(consoleBuffer, CONSOLE_WINDOW_HEIGHT, 0, "o"));
}

void test_ConsoleOutput_WriteString_Start_Col_Too_High(){
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_WriteString(consoleBuffer, 0, CONSOLE_WINDOW_WIDTH, "k"));
}

void test_ConsoleOutput_DrawRectangle(){
    const char* message[2] = {"12", "34"};
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_DrawRectangle(consoleBuffer, 0, 0, message, 2, 2));
    TEST_ASSERT_EQUAL_MEMORY("12", &consoleBuffer[0][0], 2);
    TEST_ASSERT_EQUAL_MEMORY("34", &consoleBuffer[1][0], 2);
}

void test_ConsoleOutput_DrawRectangle_TallAndThin(){
    
}
#endif // TEST
