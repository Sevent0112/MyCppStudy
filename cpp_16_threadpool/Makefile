CXX = g++
TARGET = main
OBJ = main.o thread.o 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c main.cpp

thread.o : thread.cpp
	$(CXX) -c thread.cpp

clean:
	del *.o *.exe
