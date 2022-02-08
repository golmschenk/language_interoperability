FC = gfortran
CC = gcc

all: main.exe

clean:
	rm -f *.o *.exe *.so

main.exe: main.o lib.o
	${FC} main.o lib.o -o main.exe

main.o: main.f90
	${FC} -c main.f90

lib.o: lib.c
	${CC} -c lib.c
