CXX = g++
TARGET = main
OBJ = main.o json.o 
$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c main.cpp

json.o : json/json.cpp
	$(CXX) -c json/json.cpp

clear:
	del *.exe *.o 