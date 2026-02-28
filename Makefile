# ---- Toolchain ----
CC := gcc

# ---- Flags ----
CFLAGS := -std=c11 -Wall -Wextra -Werror -Iinclude -O0 -g3
CFLAGS := -Isrc

# ---- Source files ----
SRC := \
  app/main.c \
  src/AbstractInputs.c \
  src/Chess.c \
  src/ChessConsoleInterface.c \
  src/ConsoleBuffer.c \
  src/Game.c \
  src/InfoWindow.c

# ---- Output ----
TARGET := chess

# ---- Build ----
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

# ---- Convenience ----
.PHONY: clean
clean:
	rm -f $(TARGET)
