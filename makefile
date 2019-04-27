part.o: part.cpp classtable.h
	g++ -c part.cpp
main.o: part.cpp main.cpp classtable.h
	g++ -c main.cpp
main: main.o part.o
	g++ main.o -o main
