
#include "Board.h"
#define NULL ((void *)0)

int Board_Create(Board* board){
    Piece piece;
    Piece_CreateEmpty(&piece);
    Color color = COLOR_WHITE;

    // row 0, col 0 white
    // row 0, col 1 black
    // row 1, col 0 black
    // row 1, col 1 white
    // so color = ((row ^ col) == 1) ? white : black
    //          = (((i / 8) ^ (i % 8)) == 1 ? white : black)

    for(int i = 0; i < 64; i++){
        Square_Create(&board->square[i], &piece, color);
        if(i % 8 != 7)
            color = (color == COLOR_WHITE) ? COLOR_BLACK : COLOR_WHITE;
    }
    return 0;
}

// This is ugly but overthinking this is probably not worth
int Board_ResetPieces(Board* board){

    // Initialize black pieces
    Board_GetSquare(board, "a8")->piece.type = PIECE_ROOK;
    Board_GetSquare(board, "b8")->piece.type = PIECE_KNIGHT;
    Board_GetSquare(board, "c8")->piece.type = PIECE_BISHOP;
    Board_GetSquare(board, "d8")->piece.type = PIECE_QUEEN;
    Board_GetSquare(board, "e8")->piece.type = PIECE_KING;
    Board_GetSquare(board, "f8")->piece.type = PIECE_BISHOP;
    Board_GetSquare(board, "g8")->piece.type = PIECE_KNIGHT;
    Board_GetSquare(board, "h8")->piece.type = PIECE_ROOK;

    Board_GetSquare(board, "a7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "b7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "c7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "d7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "e7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "f7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "g7")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "h7")->piece.type = PIECE_PAWN;

    for(int i = 0; i < 16; i++){
        board->square[i].piece.color = COLOR_BLACK;
    }

    // Initialize white pieces
    Board_GetSquare(board, "a1")->piece.type = PIECE_ROOK;
    Board_GetSquare(board, "b1")->piece.type = PIECE_KNIGHT;
    Board_GetSquare(board, "c1")->piece.type = PIECE_BISHOP;
    Board_GetSquare(board, "d1")->piece.type = PIECE_QUEEN;
    Board_GetSquare(board, "e1")->piece.type = PIECE_KING;
    Board_GetSquare(board, "f1")->piece.type = PIECE_BISHOP;
    Board_GetSquare(board, "g1")->piece.type = PIECE_KNIGHT;
    Board_GetSquare(board, "h1")->piece.type = PIECE_ROOK;

    Board_GetSquare(board, "a2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "b2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "c2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "d2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "e2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "f2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "g2")->piece.type = PIECE_PAWN;
    Board_GetSquare(board, "h2")->piece.type = PIECE_PAWN;

    for(int i = (64 - 16); i < 64; i++){
        board->square[i].piece.color = COLOR_WHITE;
    }


    return 0;
}

Square* Board_GetSquare(Board* board, AlgNotation alg){
    size_t index = Board_GetIndexFromAlgNotation(alg);
    if(index > 63)
        return NULL;

    return &board->square[index];
}

Piece* Board_GetPiece(Board* board, AlgNotation alg){
    Square*square = Board_GetSquare(board, alg);
    if(square == NULL)
        return NULL;

    return &square->piece;
}

size_t Board_GetIndexFromAlgNotation(AlgNotation alg){
    // rank = row (8 through 1), file = col (a through h)
    // a8 = tile 0, h1 = tile 63
    size_t row = Board_GetRowFromAlgNotation(alg);
    size_t col = Board_GetColFromAlgNotation(alg);

    if((row > 7) || (col > 7))
        return -1;

    return (row * 8) + col;
}

size_t Board_GetRowFromAlgNotation(AlgNotation alg){
    return (size_t) (8 - (alg[1] - '0'));
}

size_t Board_GetColFromAlgNotation(AlgNotation alg){
    return (size_t) (alg[0] - 'a');
}

int Board_MovePiece(Board* board, AlgNotation src, AlgNotation dest){
    if(Square_SetPiece(Board_GetSquare(board, dest), Board_GetPiece(board, src)) == 1)
        return 1;
    Board_GetPiece(board, src)->type = PIECE_NONE;
    return 0;
}

int Piece_CreateEmpty(Piece* piece){
    return Piece_Create(piece, COLOR_BLACK, PIECE_NONE);
}

int Piece_Copy(Piece* dest, Piece* src){
    dest->color = src->color;
    dest->type  = src->type;
    return 0;
}

int Piece_Create(Piece* piece, Color color, PieceType type){
    piece->color = color;
    piece->type  = type;
    return 0;
}

int Piece_IsEqual(Piece* piece1, Piece* piece2){
    return ((piece1->color == piece2->color) && (piece1->type == piece2->type));
}

int Square_Create(Square* square, Piece* piece, Color color){
    if(Square_SetPiece(square, piece) == 1)
        return 1;

    square->color = color;

    return 0;
}

int Square_Copy(Square* dest, Square* src){
    if(Piece_Copy(&dest->piece, &src->piece) == 1)
        return 1;

    dest->color = src->color;
    return 0;
}

int Square_IsEqual(Square* square1, Square* square2){
    return((square1->color == square2->color) && Piece_IsEqual(&square1->piece, &square2->piece));
}

int Square_SetPiece(Square* square, Piece* piece){
    return Piece_Copy(&square->piece, piece);
}
