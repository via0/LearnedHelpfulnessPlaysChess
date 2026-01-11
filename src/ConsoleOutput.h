
#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#define CONSOLE_WINDOW_WIDTH 90
#define CONSOLE_WINDOW_HEIGHT 60

typedef char ConsoleBuffer[CONSOLE_WINDOW_WIDTH][CONSOLE_WINDOW_HEIGHT];


int ConsoleBuffer_Create(ConsoleBuffer consoleBuffer);
void ConsoleBuffer_Print(ConsoleBuffer consoleBuffer);

#endif // CONSOLEOUTPUT_H
