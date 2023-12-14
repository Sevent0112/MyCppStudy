CXX = g++
TARGET = main
OBJ = main.o huchi.o 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c main.cpp

huchi.o : huchi.cpp
	$(CXX) -c huchi.cpp

clean : 
	del *.o *.exe