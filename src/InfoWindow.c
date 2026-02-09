#include "InfoWindow.h"
#include <stdio.h>
#include <string.h>

int InfoWindow_Initialize(struct s_InfoWindow* infoWindow){
    for(int row = 0; row < INFO_WINDOW_NUM_ROWS; row++){
        for(int col = 0; col < INFO_WINDOW_NUM_COLS; col++){
            infoWindow->info[row][col] = (char)(' ');
        }
    }

    return 0;
}

void InfoWindow_Print(struct s_InfoWindow* infoWindow){
    for(int row = 0; row < INFO_WINDOW_NUM_ROWS; row++){
        for(int col = 0; col < INFO_WINDOW_NUM_COLS; col++){
            printf("%c", infoWindow->info[row][col]);
        }
        printf("\n");
    }
    return;
}

int InfoWindow_WriteLine(struct s_InfoWindow* infoWindow, const char* line){
    int col = 0;

    // Move all the lines in the window up by one, erasing the top (oldest) line
    for(int row = 1; row < INFO_WINDOW_NUM_ROWS; row++){
        memcpy(&infoWindow->info[row-1], &infoWindow->info[row], INFO_WINDOW_NUM_COLS);
    }

    // Add the incoming message to the end
    while(line[col] != '\0'){
        if(col == INFO_WINDOW_NUM_COLS)
            return 1;
        infoWindow->info[INFO_WINDOW_NUM_ROWS-1][col] = line[col];
        col++;
    }

    return 0;
}
