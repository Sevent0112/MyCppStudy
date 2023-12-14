CXX = g++
TARGET = main
OBJ = main.o condition.o async.o

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

main.o : main.cpp
	$(CXX) -c -std=c++17 main.cpp

condition.o : condition.cpp
	$(CXX) -c -std=c++17 condition.cpp

async.o : async.cpp
	$(CXX) -c -std=c++17 async.cpp

clean :
	del *.o *.exe