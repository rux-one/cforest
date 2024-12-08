# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Version (configurable)
VERSION = 1.0.0

# Source files
SOURCES = main.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -DVERSION=\"$(VERSION)\" -c $< -o $@

# Clean rule
clean:
	$(RM) $(OBJECTS) $(TARGET)

