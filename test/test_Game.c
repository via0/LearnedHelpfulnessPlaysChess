
#ifdef TEST

#include "unity.h"

#include "Game.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Game_CreateWorks(void)
{
    Game game;
    (void) Game_Create(&game);
    TEST_ASSERT_NOT_NULL(&game);
}

#endif // TEST
