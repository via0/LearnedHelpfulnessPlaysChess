
#ifdef TEST

#include "unity.h"

#include "Game.h"
#include "AbstractInputs.h"

Game game;

void setUp(void)
{
    (void) Game_Create(&game);
    TEST_ASSERT_NOT_NULL(&game);
}

void tearDown(void)
{
}

void test_Game_Loop(void){
    TEST_ASSERT_EQUAL(0, Game_Loop(&game));
}

void test_Game_CreateInitializesStateAndInputs(void){
    TEST_ASSERT_NOT_NULL(&game);
    TEST_ASSERT_EQUAL(GAME_STATE_INIT, game.gameState);
    TEST_ASSERT_EQUAL(0, AbstractInputs_AreAnyInputsSet(&game.inputs));
    TEST_ASSERT_EQUAL(CHESS_STATE_SELECTING_START_SQUARE, game.chessState);
}

void test_Game_PressJToStartGame(void){
    TEST_ASSERT_EQUAL(0, AbstractInputs_SetInputJ(&game.inputs));
    TEST_ASSERT_EQUAL(0, Game_UpdateGameState(&game));
    TEST_ASSERT_EQUAL(GAME_STATE_PLAYING_CHESS, game.gameState);
}

void test_Game_CheckUserInput(void){
    TEST_ASSERT_EQUAL(0, Game_CheckUserInput(&game));
}

#endif // TEST
