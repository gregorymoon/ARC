all: LRU.o main.o
	g++ -std=c++11 -o LRU LRU.o main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
LRU.o: LRU.h LRU.cpp
	g++ -std=c++11 -c LRU.h LRU.cpp
clean:
	rm *.o
	rm *.gch
