##version1
# hello:hello.cpp
# 	g++ -o hello hello.cpp

## version 2
CXX = g++
TARGET = main
OBJ = hello.o main.o
$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

hello.o : hello.cpp
	$(CXX) -c hello.cpp

main.o: main.cpp	
	$(CXX) -c main.cpp

