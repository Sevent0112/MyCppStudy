CXX = g++
TARGET = main
OBJ = main.o timer.o 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c $^

timer.o : utility/timer.cpp
	$(CXX) -c $^

clean:
	del *.exe *.o 