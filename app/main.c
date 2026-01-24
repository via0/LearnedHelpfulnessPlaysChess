#include <stdio.h>
#include "Game.h"
#include "ConsoleBuffer.h"

int main(void){
    ConsoleBuffer consoleBuffer;
    if(ConsoleBuffer_Create(consoleBuffer) != 0){
        printf("It's over...\n");
    }
    ConsoleBuffer_Print(consoleBuffer);
    return 0;
}
