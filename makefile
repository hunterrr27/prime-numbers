
# Variables
CC = clang
CFLAGS = -Wall -std=c11 -I. -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL

# Target executable name
TARGET = primes

# Source files
SRC = primes.c

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Run the program
run: all
	./$(TARGET)
