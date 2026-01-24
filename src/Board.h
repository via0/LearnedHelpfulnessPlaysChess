
#ifndef BOARD_H
#define BOARD_H

typedef enum {
    PIECE_NONE = 0,
    PIECE_KING,
    PIECE_QUEEN,
    PIECE_ROOK,
    PIECE_KNIGHT,
    PIECE_BISHOP,
    PIECE_PAWN
} PieceType;

typedef enum {
    COLOR_WHITE = 0,
    COLOR_BLACK
} Color;

typedef struct s_Piece{
    PieceType type;
    Color color;
} Piece;

typedef struct s_Square{
    Piece piece;
    Color color;
} Square;

typedef struct s_Board {
    Square square[64];
} Board;

int Board_Create(Board* board);

int Piece_CreateEmpty(Piece* piece);
int Piece_Create(Piece* piece, Color color, PieceType type);
int Piece_Copy(Piece* dest, Piece* src);

int Square_Create(Square* square, Piece* piece, Color color);


#endif // BOARD_H
