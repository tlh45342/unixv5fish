# unixv5fish

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source and output files
SRC = unixv5fish.c
TARGET = unixv5fish.exe

all: build

# Build unixv5fish
build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean build artifacts
clean:
	rm -f $(OUT) $(CPPCHECK_OUTPUT)
