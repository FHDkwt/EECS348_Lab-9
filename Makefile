############ MakeFile ####################
CC = g++
CFLAGS = -Wall -g
TARGET = matrix
all: $(TARGET)
# linking object file to create executable
$(TARGET): main.o matrix.o
$(CC) $(CFLAGS) -o $(TARGET) main.o matrix.o
#compiling main.cpp to main.o
main.o: main.cpp matrix.hpp
$(CC) $(CFLAGS) -c main.cpp
# compiling matrix.cpp to matrix.o
matrix.o
