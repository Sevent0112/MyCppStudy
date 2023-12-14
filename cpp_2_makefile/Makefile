## version
CXX = g++
target = main
obj = main.o struct_union_enum.o

$(target):$(obj)
	$(CXX) -o $@ $^

main.o:
	$(CXX) -c main.cpp

struct_union_enum.o:
	$(CXX) -c struct_union_enum.cpp

clean:
	del *.o *.exe
