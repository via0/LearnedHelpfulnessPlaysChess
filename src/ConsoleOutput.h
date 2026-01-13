
#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#define CONSOLE_WINDOW_WIDTH  80
#define CONSOLE_WINDOW_HEIGHT 40

#include <stddef.h>

typedef char ConsoleBuffer[CONSOLE_WINDOW_HEIGHT][CONSOLE_WINDOW_WIDTH];

int ConsoleBuffer_Create(ConsoleBuffer consoleBuffer);
void ConsoleBuffer_Print(ConsoleBuffer consoleBuffer);

int ConsoleBuffer_WriteString(ConsoleBuffer consoleBuffer, size_t startRow, size_t startCol, const char* inString);

#endif // CONSOLEOUTPUT_H
