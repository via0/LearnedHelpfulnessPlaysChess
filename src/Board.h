
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

typedef char AlgNotation[2];

int Board_Create(Board* board);
int Board_ResetPieces(Board* board);

int Piece_CreateEmpty(Piece* piece);
int Piece_Create(Piece* piece, Color color, PieceType type);
int Piece_Copy(Piece* dest, Piece* src);
int Piece_IsEqual(Piece* piece1, Piece* piece2);

int Square_Create(Square* square, Piece* piece, Color color);
int Square_Copy(Square* dest, Square* src);
int Square_IsEqual(Square* square1, Square* square2);
int Square_SetPiece(Square* square, Piece* piece);

#endif // BOARD_H
