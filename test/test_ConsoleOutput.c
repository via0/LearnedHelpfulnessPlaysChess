
#ifdef TEST

#include "unity.h"

#include "ConsoleOutput.h"
#include <string.h>
#include <stdlib.h>

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

void test_ConsoleOutput_DrawSquare(){
    const char message[] = "12" "34";
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_DrawRectangle(consoleBuffer, 0, 0, message, 2, 2));
    TEST_ASSERT_EQUAL_MEMORY("12", &consoleBuffer[0][0], 2);
    TEST_ASSERT_EQUAL_MEMORY("34", &consoleBuffer[1][0], 2);
}

void test_ConsoleOutput_DrawRectangle(){
    const char message[] = "sc" "an" "ne" "67";
    TEST_ASSERT_EQUAL(0, ConsoleBuffer_DrawRectangle(consoleBuffer, 1, 1, message, 2, 4));

    TEST_ASSERT_EQUAL_MEMORY("sc", &consoleBuffer[1][1], 2);
    TEST_ASSERT_EQUAL_MEMORY("an", &consoleBuffer[2][1], 2);
    TEST_ASSERT_EQUAL_MEMORY("ne", &consoleBuffer[3][1], 2);
    TEST_ASSERT_EQUAL_MEMORY("67", &consoleBuffer[4][1], 2);
}

void test_ConsoleOutput_DrawRectangle_TallAndThin(){
    const char message[CONSOLE_WINDOW_HEIGHT];
    memset(message, 'a', CONSOLE_WINDOW_HEIGHT);

    TEST_ASSERT_EQUAL(0, ConsoleBuffer_DrawRectangle(consoleBuffer, 0, 0, message, 1, CONSOLE_WINDOW_HEIGHT));

    for(int row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        TEST_ASSERT_EQUAL('a', consoleBuffer[row][0]);
    }
}

void test_ConsoleOutput_DrawRectangle_ShortAndFat(){
    const char message[CONSOLE_WINDOW_WIDTH];
    memset(message, 'b', CONSOLE_WINDOW_WIDTH);

    TEST_ASSERT_EQUAL(0, ConsoleBuffer_DrawRectangle(consoleBuffer, 0, 0, message, CONSOLE_WINDOW_WIDTH, 1));

    for(int col = 0; col < CONSOLE_WINDOW_HEIGHT; col++){
        TEST_ASSERT_EQUAL('b', consoleBuffer[0][col]);
    }
}

void test_ConsoleOutput_DrawRectangle_ExactFit(){
    const char message[CONSOLE_WINDOW_WIDTH * CONSOLE_WINDOW_HEIGHT];
    memset(message, 'c', CONSOLE_WINDOW_WIDTH * CONSOLE_WINDOW_HEIGHT);

    TEST_ASSERT_EQUAL(0, ConsoleBuffer_DrawRectangle(consoleBuffer, 0, 0, message, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT));

    for(int row = 0; row < CONSOLE_WINDOW_HEIGHT; row++){
        for(int col = 0; col < CONSOLE_WINDOW_HEIGHT; col++){
            TEST_ASSERT_EQUAL('c', consoleBuffer[row][col]);
        }
    }
}

void test_ConsoleOutput_DrawRectangle_OutOfLowerBound(){
    const char message[2];
    memset(message, 'd', 2);
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_DrawRectangle(consoleBuffer, CONSOLE_WINDOW_HEIGHT-1, 0, message, 1, 2));
}

void test_ConsoleOutput_DrawRectangle_OutOfRightmostBound(){
    const char message[] = "67";
    TEST_ASSERT_EQUAL(1, ConsoleBuffer_DrawRectangle(consoleBuffer, 0, CONSOLE_WINDOW_WIDTH-1, message, 2, 1));
}
#endif // TEST
