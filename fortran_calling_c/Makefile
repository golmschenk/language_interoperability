FC = gfortran
CC = gcc
CXX = g++

all: main.exe

clean:
	rm -f *.o *.exe *.so

main.exe: main.o cMax.o
	${FC} main.o cMax.o -o main.exe

main.o: main.f90
	${FC} -c main.f90

cMax.o: cMax.c
	${CC} -c cMax.c
