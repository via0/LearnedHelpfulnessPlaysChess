
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
    for(int i = 0; i < 64; i++){
        TEST_ASSERT_EQUAL(PIECE_NONE, board.square[i].piece.type);
    }
}

void test_Board_ResetPieces(void){
    Board board;
    TEST_ASSERT_EQUAL(0, Board_Create(&board));
    TEST_ASSERT_EQUAL(0, Board_ResetPieces(&board));

    TEST_ASSERT_EQUAL(COLOR_BLACK, board.square[0].piece.color);
    TEST_ASSERT_EQUAL(PIECE_ROOK, board.square[0].piece.type);

    TEST_ASSERT_EQUAL(PIECE_NONE, board.square[30].piece.type);
}

void test_Board_GetPiece(void){
    Board board;
    TEST_ASSERT_EQUAL(0, Board_Create(&board));
    TEST_ASSERT_EQUAL(0, Board_ResetPieces(&board));

    TEST_ASSERT_NOT_NULL(Board_GetPiece(&board, "e2"));
    TEST_ASSERT_EQUAL(PIECE_PAWN, Board_GetPiece(&board, "e2")->type);
    TEST_ASSERT_EQUAL(COLOR_WHITE, Board_GetPiece(&board, "e2")->color);
}

void test_Board_GetPiece_InvalidNotationReturnsNull(void){
    Board board;
    TEST_ASSERT_EQUAL(0, Board_Create(&board));
    TEST_ASSERT_EQUAL(0, Board_ResetPieces(&board));
    TEST_ASSERT_NULL(Board_GetPiece(&board, "a9"));
    TEST_ASSERT_NULL(Board_GetPiece(&board, "B3"));
}

void test_Board_GetSquare_InvalidNotationReturnsNull(void){
    Board board;
    TEST_ASSERT_EQUAL(0, Board_Create(&board));
    TEST_ASSERT_EQUAL(0, Board_ResetPieces(&board));
    TEST_ASSERT_NULL(Board_GetSquare(&board, "a9"));
    TEST_ASSERT_NULL(Board_GetSquare(&board, "B3"));
}

void test_Board_MovePiece(void){
    Board board;
    TEST_ASSERT_EQUAL(0, Board_Create(&board));
    TEST_ASSERT_EQUAL(0, Board_ResetPieces(&board));

    TEST_ASSERT_EQUAL(PIECE_PAWN, Board_GetPiece(&board, "d2")->type);
    TEST_ASSERT_EQUAL(COLOR_WHITE, Board_GetPiece(&board, "d2")->color);
    TEST_ASSERT_EQUAL(PIECE_NONE, Board_GetPiece(&board, "d4")->type);
    TEST_ASSERT_EQUAL(0, Board_MovePiece(&board, "d2", "d4"));

    TEST_ASSERT_EQUAL(PIECE_PAWN, Board_GetPiece(&board, "d4")->type);
    TEST_ASSERT_EQUAL(COLOR_WHITE, Board_GetPiece(&board, "d4")->color);
    TEST_ASSERT_EQUAL(PIECE_NONE, Board_GetPiece(&board, "d2")->type);
}

void test_Board_GetIndexFromAlgNotation(void){
    AlgNotation alg = "a8";
    //for(int i = 0; i < 64; i++){
    //    printf("Testing %c%c", alg[0], alg[1]);
    //    fflush(stdout);
    //    TEST_ASSERT_EQUAL(i, Board_GetIndexFromAlgNotation(alg));
    //    if(i % 8 == 0){
    //        alg[0] = 'a';
    //        alg[1] -= 1;
    //    } else {
    //        alg[0] += 1;
    //    }
    //}
    TEST_ASSERT_EQUAL((0 * 8) + 0, Board_GetIndexFromAlgNotation("a8"));
    TEST_ASSERT_EQUAL((0 * 8) + 1, Board_GetIndexFromAlgNotation("b8"));
    TEST_ASSERT_EQUAL((0 * 8) + 2, Board_GetIndexFromAlgNotation("c8"));
    TEST_ASSERT_EQUAL((0 * 8) + 3, Board_GetIndexFromAlgNotation("d8"));
    TEST_ASSERT_EQUAL((0 * 8) + 4, Board_GetIndexFromAlgNotation("e8"));
    TEST_ASSERT_EQUAL((0 * 8) + 5, Board_GetIndexFromAlgNotation("f8"));
    TEST_ASSERT_EQUAL((0 * 8) + 6, Board_GetIndexFromAlgNotation("g8"));
    TEST_ASSERT_EQUAL((0 * 8) + 7, Board_GetIndexFromAlgNotation("h8"));

    TEST_ASSERT_EQUAL((1 * 8) + 0, Board_GetIndexFromAlgNotation("a7"));
    TEST_ASSERT_EQUAL((1 * 8) + 1, Board_GetIndexFromAlgNotation("b7"));
    TEST_ASSERT_EQUAL((1 * 8) + 2, Board_GetIndexFromAlgNotation("c7"));
    TEST_ASSERT_EQUAL((1 * 8) + 3, Board_GetIndexFromAlgNotation("d7"));
    TEST_ASSERT_EQUAL((1 * 8) + 4, Board_GetIndexFromAlgNotation("e7"));
    TEST_ASSERT_EQUAL((1 * 8) + 5, Board_GetIndexFromAlgNotation("f7"));
    TEST_ASSERT_EQUAL((1 * 8) + 6, Board_GetIndexFromAlgNotation("g7"));
    TEST_ASSERT_EQUAL((1 * 8) + 7, Board_GetIndexFromAlgNotation("h7"));

    TEST_ASSERT_EQUAL((2 * 8) + 0, Board_GetIndexFromAlgNotation("a6"));
    TEST_ASSERT_EQUAL((2 * 8) + 1, Board_GetIndexFromAlgNotation("b6"));
    TEST_ASSERT_EQUAL((2 * 8) + 2, Board_GetIndexFromAlgNotation("c6"));
    TEST_ASSERT_EQUAL((2 * 8) + 3, Board_GetIndexFromAlgNotation("d6"));
    TEST_ASSERT_EQUAL((2 * 8) + 4, Board_GetIndexFromAlgNotation("e6"));
    TEST_ASSERT_EQUAL((2 * 8) + 5, Board_GetIndexFromAlgNotation("f6"));
    TEST_ASSERT_EQUAL((2 * 8) + 6, Board_GetIndexFromAlgNotation("g6"));
    TEST_ASSERT_EQUAL((2 * 8) + 7, Board_GetIndexFromAlgNotation("h6"));

    TEST_ASSERT_EQUAL((3 * 8) + 0, Board_GetIndexFromAlgNotation("a5"));
    TEST_ASSERT_EQUAL((3 * 8) + 1, Board_GetIndexFromAlgNotation("b5"));
    TEST_ASSERT_EQUAL((3 * 8) + 2, Board_GetIndexFromAlgNotation("c5"));
    TEST_ASSERT_EQUAL((3 * 8) + 3, Board_GetIndexFromAlgNotation("d5"));
    TEST_ASSERT_EQUAL((3 * 8) + 4, Board_GetIndexFromAlgNotation("e5"));
    TEST_ASSERT_EQUAL((3 * 8) + 5, Board_GetIndexFromAlgNotation("f5"));
    TEST_ASSERT_EQUAL((3 * 8) + 6, Board_GetIndexFromAlgNotation("g5"));
    TEST_ASSERT_EQUAL((3 * 8) + 7, Board_GetIndexFromAlgNotation("h5"));

    TEST_ASSERT_EQUAL((4 * 8) + 0, Board_GetIndexFromAlgNotation("a4"));
    TEST_ASSERT_EQUAL((4 * 8) + 1, Board_GetIndexFromAlgNotation("b4"));
    TEST_ASSERT_EQUAL((4 * 8) + 2, Board_GetIndexFromAlgNotation("c4"));
    TEST_ASSERT_EQUAL((4 * 8) + 3, Board_GetIndexFromAlgNotation("d4"));
    TEST_ASSERT_EQUAL((4 * 8) + 4, Board_GetIndexFromAlgNotation("e4"));
    TEST_ASSERT_EQUAL((4 * 8) + 5, Board_GetIndexFromAlgNotation("f4"));
    TEST_ASSERT_EQUAL((4 * 8) + 6, Board_GetIndexFromAlgNotation("g4"));
    TEST_ASSERT_EQUAL((4 * 8) + 7, Board_GetIndexFromAlgNotation("h4"));

    TEST_ASSERT_EQUAL((5 * 8) + 0, Board_GetIndexFromAlgNotation("a3"));
    TEST_ASSERT_EQUAL((5 * 8) + 1, Board_GetIndexFromAlgNotation("b3"));
    TEST_ASSERT_EQUAL((5 * 8) + 2, Board_GetIndexFromAlgNotation("c3"));
    TEST_ASSERT_EQUAL((5 * 8) + 3, Board_GetIndexFromAlgNotation("d3"));
    TEST_ASSERT_EQUAL((5 * 8) + 4, Board_GetIndexFromAlgNotation("e3"));
    TEST_ASSERT_EQUAL((5 * 8) + 5, Board_GetIndexFromAlgNotation("f3"));
    TEST_ASSERT_EQUAL((5 * 8) + 6, Board_GetIndexFromAlgNotation("g3"));
    TEST_ASSERT_EQUAL((5 * 8) + 7, Board_GetIndexFromAlgNotation("h3"));

    TEST_ASSERT_EQUAL((6 * 8) + 0, Board_GetIndexFromAlgNotation("a2"));
    TEST_ASSERT_EQUAL((6 * 8) + 1, Board_GetIndexFromAlgNotation("b2"));
    TEST_ASSERT_EQUAL((6 * 8) + 2, Board_GetIndexFromAlgNotation("c2"));
    TEST_ASSERT_EQUAL((6 * 8) + 3, Board_GetIndexFromAlgNotation("d2"));
    TEST_ASSERT_EQUAL((6 * 8) + 4, Board_GetIndexFromAlgNotation("e2"));
    TEST_ASSERT_EQUAL((6 * 8) + 5, Board_GetIndexFromAlgNotation("f2"));
    TEST_ASSERT_EQUAL((6 * 8) + 6, Board_GetIndexFromAlgNotation("g2"));
    TEST_ASSERT_EQUAL((6 * 8) + 7, Board_GetIndexFromAlgNotation("h2"));

    TEST_ASSERT_EQUAL((7 * 8) + 0, Board_GetIndexFromAlgNotation("a1"));
    TEST_ASSERT_EQUAL((7 * 8) + 1, Board_GetIndexFromAlgNotation("b1"));
    TEST_ASSERT_EQUAL((7 * 8) + 2, Board_GetIndexFromAlgNotation("c1"));
    TEST_ASSERT_EQUAL((7 * 8) + 3, Board_GetIndexFromAlgNotation("d1"));
    TEST_ASSERT_EQUAL((7 * 8) + 4, Board_GetIndexFromAlgNotation("e1"));
    TEST_ASSERT_EQUAL((7 * 8) + 5, Board_GetIndexFromAlgNotation("f1"));
    TEST_ASSERT_EQUAL((7 * 8) + 6, Board_GetIndexFromAlgNotation("g1"));
    TEST_ASSERT_EQUAL((7 * 8) + 7, Board_GetIndexFromAlgNotation("h1"));
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

void test_Piece_IsEqual(void){
    Piece piece1, piece2;
    piece1.color = COLOR_WHITE;
    piece1.type = PIECE_QUEEN;
    piece2.color = COLOR_BLACK;
    piece2.type = PIECE_QUEEN;

    TEST_ASSERT_NOT_EQUAL(1, Piece_IsEqual(&piece1, &piece2));
    piece2.color = COLOR_WHITE;
    TEST_ASSERT_EQUAL(1, Piece_IsEqual(&piece1, &piece2));
    piece1.type = PIECE_ROOK;
    TEST_ASSERT_NOT_EQUAL(1, Piece_IsEqual(&piece1, &piece2));
    piece2.type = PIECE_ROOK;
    TEST_ASSERT_EQUAL(1, Piece_IsEqual(&piece1, &piece2));
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

void test_Square_SetPiece(void){
    Square square;
    Piece piece;
    TEST_ASSERT_EQUAL(0, Piece_Create(&piece, COLOR_BLACK, PIECE_PAWN));
    TEST_ASSERT_EQUAL(0, Square_Create(&square, &piece, COLOR_WHITE));
    TEST_ASSERT_EQUAL(0, Piece_Create(&piece, COLOR_WHITE, PIECE_KNIGHT));

    TEST_ASSERT_EQUAL(0, Piece_IsEqual(&piece, &square.piece));
    TEST_ASSERT_EQUAL(0, Square_SetPiece(&square, &piece));
    TEST_ASSERT_EQUAL(1, Piece_IsEqual(&piece, &square.piece));

    TEST_ASSERT_EQUAL(PIECE_KNIGHT, piece.type);
    piece.type = PIECE_QUEEN;
    TEST_ASSERT_NOT_EQUAL(1, Piece_IsEqual(&piece, &square.piece));
    TEST_ASSERT_EQUAL(0, Square_SetPiece(&square, &piece));
    TEST_ASSERT_EQUAL(1, Piece_IsEqual(&piece, &square.piece));
}

void test_Board_GetSquare(void){
    Board board;
    AlgNotation alg = "a8";
    TEST_ASSERT_EQUAL_PTR(Board_GetSquare(&board, alg), &board.square[0]);
    TEST_ASSERT_NOT_NULL(Board_GetSquare(&board, alg));
    TEST_ASSERT_NOT_NULL(Board_GetSquare(&board, "e3"));
    TEST_ASSERT_NOT_NULL(Board_GetSquare(&board, "h8"));

}

void test_IndexFromAlgNotation(void){
    TEST_ASSERT_EQUAL(0, Board_GetIndexFromAlgNotation("a8"));
}

#endif // TEST
