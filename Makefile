# unixv5fish

# Compiler and flags
CC = gcc

# Compiler flags: enable all warnings and use the C99 standard
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and output files
SRC = $(SRC_DIR)/unixv5fish.c
TARGET = $(BUILD_DIR)/unixv5fish.exe

all: build

# Build unixv5fish
build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

cppcheck:
	cppcheck $(SRC_DIR)/unixv5fish.c

# Clean build artifacts
clean:
	rm -f $(OUT) $(CPPCHECK_OUTPUT)
