#version

CXX = g++
TARGET = main
OBJ = main.o 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c $^