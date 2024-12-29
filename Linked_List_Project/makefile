# Compiler and flags
CC := g++
CFLAGS := -Wall -g

# Get all source files in current directory
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

# Detect operating system
ifeq ($(OS),Windows_NT)
	DETECTED_OS := Windows
	TARGET := program.exe
	RM := del /F /Q
	RMDIR := rmdir /S /Q
	MKDIR := mkdir
	SEP := \\
	EXE := .exe
else
	DETECTED_OS := $(shell uname -s)
	TARGET := program
	RM := rm -f
	RMDIR := rm -rf
	MKDIR := mkdir -p
	SEP := /
	EXE :=
endif

# File extension (change based on language: .cpp, .c, etc.)
EXT := cpp

# Default target
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilation rule
%.o: %.$(EXT)
	$(CC) $(CFLAGS) -c $< -o $@

# Generate dependencies
depend: $(SOURCES)
	$(CC) $(CFLAGS) -MM $(SOURCES) > .depend

-include .depend

# Run the program
run: $(TARGET)
	.$(SEP)$(TARGET)

# Clean up
clean:
	$(RM) $(TARGET) $(OBJECTS) .depend

# Help target
help:
	@echo "Available targets:"
	@echo "  all	: Build the program (default)"
	@echo "  run	: Build and run the program"
	@echo "  clean	: Remove compiled files"
	@echo "  depend	: Generate dependencies"
	@echo "  help	: Show this help message"
	@echo ""
	@echo "Variables that can be modified:"
	@echo "  CC	: Compiler (currently '$(CC)')"
	@echo "  CFLAGS	: Compiler flags (currently '$(CFLAGS)')"
	@echo "  EXT	: Source file extension (currently '$(EXT)')"
	@echo "  TARGET	: Executable name (currently '$(TARGET)')"
	@echo ""
	@echo "Detected operating system: $(DETECTED_OS)"

.PHONY: all run clean depend help
