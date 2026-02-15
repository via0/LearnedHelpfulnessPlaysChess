
#ifdef TEST

#include "unity.h"

#include "Game.h"
#include "AbstractInputs.h"

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

void test_Game_Loop(void){
    Game game;
    (void) Game_Create(&game);
    TEST_ASSERT_EQUAL(0, Game_Loop(&game));
}

void test_Game_CreateInitializesStateAndInputs(void){
    Game game;
    (void) Game_Create(&game);
    TEST_ASSERT_NOT_NULL(&game);
    TEST_ASSERT_EQUAL(GAME_STATE_INIT, game.state);
    TEST_ASSERT_EQUAL(0, AbstractInputs_AreAnyInputsSet(&game.inputs));
}

void test_Game_PressJToStartGame(void){
    Game game;
    (void) Game_Create(&game);
    TEST_ASSERT_EQUAL(0, AbstractInputs_SetInputJ(&game.inputs));
    TEST_ASSERT_EQUAL(0, Game_Loop(&game));
    TEST_ASSERT_EQUAL(GAME_STATE_PLAYING_CHESS, game.state);
}
#endif // TEST
