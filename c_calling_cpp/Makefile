FC = gfortran
CC = gcc
CXX = g++

all: main.exe

clean:
	rm -f *.o *.exe *.so

main.exe: main.o libcppMin.so
	${CC} main.o -L. -lcppMin -o main.exe

main.o: main.c cppMin.hpp
	${CC} -c main.c

libcppMin.so: cppMin.cpp cppMin.hpp
	${CXX} -fPIC -shared cppMin.cpp -o libcppMin.so