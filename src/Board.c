
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

int Square_Create(Square* square, Piece* piece, Color color){
    if(Piece_Copy(&square->piece, piece) == 1)
        return 1;

    square->color = color;

    return 0;
}
