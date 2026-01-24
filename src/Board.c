
#include "Board.h"
#define NULL ((void *)0)

int Board_Create(Board* board){
    Piece piece;
    Piece_CreateEmpty(&piece);
    for(int i = 0; i < 64; i++){
        Square_Create(&board->square[i], &piece, \
                (i%2 == 0) ? COLOR_WHITE : COLOR_BLACK);
    }
    return 0;
}

// This is ugly but overthinking this is probably not worth
int Board_ResetPieces(Board* board){

    // Initialize black pieces
    board->square[(8 * 0) + 0].piece.type = PIECE_ROOK;
    board->square[(8 * 0) + 7].piece.type = PIECE_ROOK;
    board->square[(8 * 0) + 1].piece.type = PIECE_KNIGHT;
    board->square[(8 * 0) + 6].piece.type = PIECE_KNIGHT;
    board->square[(8 * 0) + 2].piece.type = PIECE_BISHOP;
    board->square[(8 * 0) + 5].piece.type = PIECE_BISHOP;
    board->square[(8 * 0) + 3].piece.type = PIECE_QUEEN;
    board->square[(8 * 0) + 4].piece.type = PIECE_KING;

    for(int col = 0; col < 8; col++){
        board->square[(8 * 1) + col].piece.type = PIECE_PAWN;
    }

    for(int i = 0; i < 16; i++){
        board->square[i].piece.color = COLOR_BLACK;
    }

    // Initialize white pieces
    board->square[(8 * 7) + 0].piece.type = PIECE_ROOK;
    board->square[(8 * 7) + 7].piece.type = PIECE_ROOK;
    board->square[(8 * 7) + 1].piece.type = PIECE_KNIGHT;
    board->square[(8 * 7) + 6].piece.type = PIECE_KNIGHT;
    board->square[(8 * 7) + 2].piece.type = PIECE_BISHOP;
    board->square[(8 * 7) + 5].piece.type = PIECE_BISHOP;
    board->square[(8 * 7) + 3].piece.type = PIECE_QUEEN;
    board->square[(8 * 7) + 4].piece.type = PIECE_KING;

    for(int col = 0; col < 8; col++){
        board->square[(8 * 6) + col].piece.type = PIECE_PAWN;
    }

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

size_t Board_GetIndexFromAlgNotation(AlgNotation alg){
    // rank = row, file = col
    // a8 = tile 0, h1 = tile 63
    size_t row = (size_t) (8 - (alg[1] - '0'));
    size_t col = (size_t) (alg[0] - 'a');

    return (row * 8) + col;
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
