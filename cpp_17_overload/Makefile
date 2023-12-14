CXX = g++
TARGET = main
OBJ = main.o overload.o

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c main.cpp

overload.o : overload.cpp
	$(CXX) -c overload.cpp


clean:
	del *.o *.exe