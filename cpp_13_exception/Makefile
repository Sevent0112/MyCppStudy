main:exception.o main.o
	g++ -o main exception.o main.o

exception.o : exception.cpp
	g++ -c exception.cpp

main.o : main.cpp
	g++ -c main.cpp

clean:
	del *.o *.exe *.log

run:
	./main > exception.log 2> err.log