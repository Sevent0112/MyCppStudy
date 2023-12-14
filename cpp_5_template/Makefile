#version

CXX = g++
TARGET = main
OBJ = main.o template.o

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o:
	$(CXX) -c main.cpp

template.o:
	$(CXX) -c template.cpp

clean:
	del *.o *.exe