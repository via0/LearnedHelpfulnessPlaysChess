
#ifdef TEST

#include "unity.h"

#include "InfoWindow.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_InfoWindowInitialize(void){
    struct s_InfoWindow infoWindow;
    TEST_ASSERT_EQUAL(0, InfoWindow_Initialize(&infoWindow));
    TEST_ASSERT_EQUAL_MEMORY(" ", &infoWindow.info[0][0], 1);
    TEST_ASSERT_EQUAL_MEMORY(" ", &infoWindow.info[1][0], 1);
    TEST_ASSERT_EQUAL_MEMORY(" ", &infoWindow.info[INFO_WINDOW_NUM_ROWS-1][INFO_WINDOW_NUM_COLS-1], 1);
}

//void test_InfoWindowPrint(void){
//    struct s_InfoWindow infoWindow;
//    TEST_ASSERT_EQUAL(0, InfoWindow_Initialize(&infoWindow));
//    InfoWindow_Print(&infoWindow);
//}

void test_InfoWindowWrite(void){
    struct s_InfoWindow infoWindow;
    TEST_ASSERT_EQUAL(0, InfoWindow_Initialize(&infoWindow));

    TEST_ASSERT_EQUAL(0, InfoWindow_WriteLine(&infoWindow, "hello world"));
    TEST_ASSERT_EQUAL_MEMORY("hello world", &infoWindow.info[INFO_WINDOW_NUM_ROWS-1], 11);

    char message[] = "my name chef";

    TEST_ASSERT_EQUAL(0, InfoWindow_WriteLine(&infoWindow, (const char*) message));
    TEST_ASSERT_EQUAL_MEMORY("my name chef", &infoWindow.info[INFO_WINDOW_NUM_ROWS-1], sizeof(message) - 1);
    TEST_ASSERT_EQUAL_MEMORY("hello world", &infoWindow.info[INFO_WINDOW_NUM_ROWS-2], 11);
}

void test_InfoWindow_WriteReallyLongMessageCutsOffMessageAndReturns1(void){
    char message[] = \
        "Jack Zebra\
         Markiplier\
         SmoshIanAn\
         dAnthony  \
         Anthony Fa\
         ntano is m\
         y hero. I \
         love him <3";

    struct s_InfoWindow infoWindow;
    TEST_ASSERT_EQUAL(0, InfoWindow_Initialize(&infoWindow));

    TEST_ASSERT_EQUAL(1, InfoWindow_WriteLine(&infoWindow, (const char*) message));
    TEST_ASSERT_EQUAL_MEMORY(message, &infoWindow.info[INFO_WINDOW_NUM_ROWS-1], INFO_WINDOW_NUM_COLS);
    TEST_ASSERT_EQUAL(0, InfoWindow_WriteLine(&infoWindow, "blueface"));
    TEST_ASSERT_EQUAL_MEMORY(message, &infoWindow.info[INFO_WINDOW_NUM_ROWS-2], INFO_WINDOW_NUM_COLS);
    TEST_ASSERT_EQUAL_MEMORY("blueface", &infoWindow.info[INFO_WINDOW_NUM_ROWS-1], sizeof("blueface")-1);
}

void test_InfoWindow_WriteABunchOfMessages(void){
    struct s_InfoWindow infoWindow;
    TEST_ASSERT_EQUAL(0, InfoWindow_Initialize(&infoWindow));

    char message[INFO_WINDOW_NUM_COLS];
    int messageLength;

    for(int row = 0; row < INFO_WINDOW_NUM_ROWS; row++){
        sprintf(message, "We are writing for the %02d'th time fr", row);
        TEST_ASSERT_EQUAL(0, InfoWindow_WriteLine(&infoWindow, (const char*) message));
    }

    for(int row = 0; row < INFO_WINDOW_NUM_ROWS; row++){
        sprintf(message, "We are writing for the %02d'th time fr", row);
        TEST_ASSERT_EQUAL_MEMORY(message, &infoWindow.info[row], strlen(message));
    }

    sprintf(message, "We are writing for the 20'th time fr");
    TEST_ASSERT_EQUAL(0, InfoWindow_WriteLine(&infoWindow, (const char*) message));

    for(int row = 0; row < INFO_WINDOW_NUM_ROWS; row++){
        sprintf(message, "We are writing for the %02d'th time fr", row+1);
        TEST_ASSERT_EQUAL_MEMORY(message, &infoWindow.info[row], strlen(message));
    }
//    InfoWindow_Print(&infoWindow);
}

#endif // TEST
