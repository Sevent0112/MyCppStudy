CXX = g++
TARGET = main
OBJ = main.o log.o 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c main.cpp

log.o : log/log.cpp
	$(CXX) -c log/log.cpp

clean:
	del *.o *.exe