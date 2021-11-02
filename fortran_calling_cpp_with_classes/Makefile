FC = gfortran
CXX = g++

all: main.exe

clean:
	rm -df *.o *.exe *.so

main.exe: main.o librobot.so
	${FC} main.o -L. -lrobot -o main.exe

main.o: main.f90
	${FC} -c main.f90

librobot.so: robot.cpp robot.hpp robot.h
	${CXX} -fPIC -shared robot.cpp -o librobot.so
