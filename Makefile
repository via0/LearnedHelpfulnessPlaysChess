# ---- Toolchain ----
CC := gcc

# ---- Flags ----
CFLAGS := -std=c11 -Wall -Wextra -Werror -Iinclude -O0 -g
CFLAGS := -Isrc

# ---- Source files ----
SRC := \
  app/main.c \
  src/Game.c \
  src/ConsoleBuffer.c

# ---- Output ----
TARGET := chess

# ---- Build ----
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

# ---- Convenience ----
.PHONY: clean
clean:
	rm -f $(TARGET)
