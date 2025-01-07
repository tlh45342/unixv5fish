# unixv5fish

# Compiler and flags
CC = gcc

# Compiler flags: enable all warnings and use the C99 standard
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = src
BUILD_DIR = build

# Determine the target and installation directory based on OS
ifeq ($(OS),Windows_NT)
    TARGET = unixv5fish.exe
    DESTDIR = C:/MinGW/msys/1.0/bin/
else
    TARGET = unixv5fish
    DESTDIR = /usr/local/bin/
endif

# Source and output files
SRC = $(SRC_DIR)/unixv5fish.c

all: build

# Build unixv5fish
build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Static analysis with cppcheck
cppcheck:
	cppcheck $(SRC_DIR)/unixv5fish.c

# Install the executable
install: build
	mkdir -p $(DESTDIR)
	cp $(TARGET) $(DESTDIR)

# Clean build artifacts
clean:
	rm -f $(TARGET)