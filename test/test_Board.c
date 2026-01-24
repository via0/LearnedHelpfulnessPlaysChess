
#ifdef TEST

#include "unity.h"

#include "Board.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Board_Create(void){
    Board board;
    TEST_ASSERT_EQUAL(0, Board_Create(&board));
}

void test_Piece_Create(void){
    Piece piece;
    TEST_ASSERT_EQUAL(0, Piece_Create(&piece, COLOR_BLACK, PIECE_QUEEN));
    TEST_ASSERT_EQUAL(COLOR_BLACK, piece.color);
    TEST_ASSERT_EQUAL(PIECE_QUEEN, piece.type);
}

void test_Piece_CreateWithoutParameters(void){
    Piece piece;
    TEST_ASSERT_EQUAL(0, Piece_CreateEmpty(&piece));
    TEST_ASSERT_EQUAL(PIECE_NONE, piece.type);
}

void test_Piece_Copy(void){
    Piece og;
    Piece copy;
    TEST_ASSERT_EQUAL(0, Piece_Create(&og, COLOR_WHITE, PIECE_PAWN));
    TEST_ASSERT_EQUAL(0, Piece_Copy(&copy, &og));
    TEST_ASSERT_EQUAL(1, Piece_IsEqual(&og, &copy));
}

void test_Square_Create(void){
    Square square;
    Piece piece;

    TEST_ASSERT_EQUAL(0, Piece_Create(&piece, COLOR_WHITE, PIECE_BISHOP));
    TEST_ASSERT_EQUAL(0, Square_Create(&square, &piece, COLOR_BLACK));
    
    TEST_ASSERT_EQUAL(COLOR_BLACK, square.color);
    TEST_ASSERT_EQUAL(COLOR_WHITE, square.piece.color);
    TEST_ASSERT_EQUAL(PIECE_BISHOP, square.piece.type);
}

void test_Square_Copy(void){
    Square og;
    Square copy;
    Piece piece;

    TEST_ASSERT_EQUAL(0, Piece_Create(&piece, COLOR_BLACK, PIECE_KNIGHT));

    TEST_ASSERT_EQUAL(0, Square_Create(&og, &piece, COLOR_WHITE));

    TEST_ASSERT_EQUAL(0, Square_Copy(&copy, &og));

    TEST_ASSERT_EQUAL(1, Square_IsEqual(&og, &copy));
}
#endif // TEST
