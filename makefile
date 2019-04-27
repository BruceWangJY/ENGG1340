part.o: part.cpp classtable.h
	g++ -c part.cpp
main.o: part.o main.cpp
	g++ -c main.cpp
main: main.o
	g++ main.o -o main
