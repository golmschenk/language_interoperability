CC = gcc
CXX = g++

all: main.exe

clean:
	rm -f *.o *.exe *.so

main.exe: main.o librobot.so
	${CC} main.o -L. -lrobot -o main.exe

main.o: main.c robot.h
	${CC} -c main.c

librobot.so: robot.cpp robot.hpp robot.h
	${CXX} -fPIC -shared robot.cpp -o librobot.so
