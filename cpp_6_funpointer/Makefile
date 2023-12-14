CXX = g++
TARGET = main
OBJ = norm.o main.o 
$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

norm.o:norm.cpp
	$(CXX) -c norm.cpp

main.o:main.cpp
	$(CXX) -c main.cpp

clean:
	del *.o *.exe