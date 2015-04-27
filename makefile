all: LRU.o main.o ARC.o
	g++ -std=c++11 -o main LRU.o main.o ARC.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
LRU.o: LRU.h LRU.cpp
	g++ -std=c++11 -c LRU.h LRU.cpp
ARC.o: ARC.h ARC.cpp LRU.cpp LRU.h
	g++ -std=c++11 -c ARC.h ARC.cpp LRU.cpp LRU.h
clean:
	rm *.o
	rm *.gch
