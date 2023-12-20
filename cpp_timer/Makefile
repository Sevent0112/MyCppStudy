CXX = g++
TARGET = main
OBJ = main.o timer.o timer_manager.o 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c $^

timer.o : timer/timer.cpp
	$(CXX) -c $^

timer_manager.o : timer/timer_manager.cpp
	$(CXX) -c $^

clean:
	del *.exe *.o 