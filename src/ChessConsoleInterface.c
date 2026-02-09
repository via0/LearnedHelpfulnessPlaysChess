
#include "ChessConsoleInterface.h"
#include "InfoWindow.h"
#include <string.h>

// Coordinates of chessboard on console GUI
#define CONSOLE_BOARD_ORIGIN_X 2
#define CONSOLE_BOARD_ORIGIN_Y (((CONSOLE_WINDOW_HEIGHT - CONSOLE_BOARD_HEIGHT) / 2) + 1)

// Coordinates of info window on console GUI
#define CONSOLE_INFO_WINDOW_ORIGIN_X (CONSOLE_WINDOW_WIDTH - INFO_WINDOW_NUM_COLS - 2)
#define CONSOLE_INFO_WINDOW_ORIGIN_Y (CONSOLE_WINDOW_HEIGHT - INFO_WINDOW_NUM_ROWS - 2)

const ConsoleSquare EmptyConsoleSquareBlack =
                "+--------"
                "|........"
                "|........"
                "|........";

const ConsoleSquare EmptyConsoleSquareWhite =
                "+--------"
                "|        "
                "|        "
                "|        ";


ConsoleBuffer consoleBuffer;
Board board;
struct s_InfoWindow infoWindow;

int Console_Init(void){
    if(ConsoleBuffer_Create(consoleBuffer) == 1)
        return 1;
    if(Board_Create(&board) == 1)
        return 1;
    if(Board_ResetPieces(&board) == 1)
        return 1;
    if(InfoWindow_Initialize(&infoWindow))
        return 1;
    return 0;
}

int Console_Render(void){
    return ConsoleBuffer_Print(consoleBuffer);
}

int Console_DrawSquareByAlgNotation(AlgNotation alg){
    size_t boardRow, boardCol, consoleBufferRow, consoleBufferCol;
    Square* square;
    ConsoleSquare consoleSquare;
    const ConsoleSquare* defaultSquare;

    // Remember a8 is top left (0, 0)
    boardRow = Board_GetRowFromAlgNotation(alg);
    boardCol = Board_GetColFromAlgNotation(alg);

    consoleBufferRow = CONSOLE_BOARD_ORIGIN_Y + (CONSOLE_SQUARE_HEIGHT * boardRow);
    consoleBufferCol = CONSOLE_BOARD_ORIGIN_X + (CONSOLE_SQUARE_WIDTH * boardCol);

    square = Board_GetSquare(&board, alg);
    if(square == NULL)
        return 1;

    defaultSquare = (square->color == COLOR_WHITE) ? EmptyConsoleSquareWhite : EmptyConsoleSquareBlack;

    if(ConsoleSquare_Set(consoleSquare, *defaultSquare) == 1)
        return 1;

    if(ConsoleSquare_WritePiece(consoleSquare, Board_GetPiece(&board, alg)) == 1)
        return 1;

    if(ConsoleBuffer_DrawRectangle(consoleBuffer, consoleBufferRow, consoleBufferCol,
                (const char*) consoleSquare, CONSOLE_SQUARE_WIDTH, CONSOLE_SQUARE_HEIGHT)
            == 1)
        return 1;

    return 0;
}

int Console_DrawConsoleSquare(const ConsoleSquare consoleSquare, size_t originX, size_t originY){
    return ConsoleBuffer_DrawRectangle(consoleBuffer, originY, originX, (const char*) consoleSquare, CONSOLE_SQUARE_WIDTH, CONSOLE_SQUARE_HEIGHT);
}

int Console_DrawBoard(void){
    AlgNotation alg;
    for(char rank = '1'; rank <= '8'; rank++){
        alg[1] = rank;

        for(char file = 'a'; file <= 'h'; file++){
            alg[0] = file;
            Console_DrawSquareByAlgNotation(alg);
        }
    }
    return 0;
}

int Console_DrawInfoWindow(void){
    // Janky implementatoin because ConsoleBuffer_DrawRectangle expects a 1D array and
    // InfoWindow is a 2D array (and ConsoleBuffer_WriteString expects a null terminated
    // string, and InfoWindow doesn't have those)
    // It would be better to reimplement InfoWindow as a 1D array
    const char* infoLinePointer;
    for(int row = 0; row < INFO_WINDOW_NUM_ROWS; row++){
        infoLinePointer = &infoWindow.info[row];
        if(ConsoleBuffer_DrawRectangle(consoleBuffer,     \
                    (CONSOLE_INFO_WINDOW_ORIGIN_Y + row), \
                    (CONSOLE_INFO_WINDOW_ORIGIN_X),       \
                    (const char*) infoLinePointer,        \
                    INFO_WINDOW_NUM_COLS,                 \
                    1) != 0){
            return 1;
        }
    }
    return 0;
}

int Console_WriteInfoLine(const char* line){
    return InfoWindow_WriteLine(&infoWindow, line);
}

int ConsoleSquare_Set(ConsoleSquare dest, const ConsoleSquare value){
    memcpy(dest, value, sizeof(ConsoleSquare));
    return 0;
}

int ConsoleSquare_WritePiece(ConsoleSquare consoleSquare, Piece* piece){
    char c_color;
    char c_type;

    switch(piece->type){
        case PIECE_NONE:
            return;
        case PIECE_ROOK:
            c_type = 'R';
            break;
        case PIECE_KNIGHT:
            c_type = 'N';
            break;
        case PIECE_BISHOP:
            c_type = 'B';
            break;
        case PIECE_QUEEN:
            c_type = 'Q';
            break;
        case PIECE_KING:
            c_type = 'K';
            break;
        case PIECE_PAWN:
            c_type = 'P';
            break;
        default:
            c_type = '?';
            break;
    }

    c_color = (piece->color == COLOR_WHITE) ? 'W' : 'B';

    consoleSquare[CONSOLE_SQUARE_PIECE_NAME_OFFSET]     = c_color;
    consoleSquare[CONSOLE_SQUARE_PIECE_NAME_OFFSET + 1] = c_type;

    return 0;
}
