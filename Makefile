# Compiler g++
CC = g++

# Compiler flags: -Wall for warnings, -g for debugging info
CFLAGS = -Wall -g

# Target executable name
TARGET = matrix

# Default target: build the executable
all: $(TARGET)

# Link object file to create executable
$(TARGET): main.o matrix.o
$(CC) $(CFLAGS) -o $(TARGET) main.o matrix.o

# Compile main.cpp into main.o
main.o: main.cpp matrix.hpp
$(CC) $(CFLAGS) -c main.cpp

# Compile matrix.cpp into matrix.o
matrix.o
