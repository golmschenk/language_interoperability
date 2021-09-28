FC = gfortran
CC = gcc

hello.exe: hello.o max.o
	${FC} hello.o max.o -o hello.exe

hello.o: hello.f90
	${FC} -c hello.f90

max.o: max.c
	${CC} -c max.c
