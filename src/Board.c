
#include "Board.h"

int Board_Create(Board* board){
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
    if(Piece_Copy(&square->piece, piece) == 1)
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
