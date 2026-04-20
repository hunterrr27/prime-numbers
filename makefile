# Variables
CC = clang
CFLAGS = -Wall -std=c11 -Iinclude -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL

# Directories
SRC_DIR = src
BIN_DIR = bin

# Target executable name
TARGET = $(BIN_DIR)/primes

# Source files (prefixed with src/)
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/prime_gen.c $(SRC_DIR)/modes.c \
      $(SRC_DIR)/render.c $(SRC_DIR)/ui.c $(SRC_DIR)/state.c

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -rf $(BIN_DIR)

# Run the program
run: all
	./$(TARGET)