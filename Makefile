FC = gfortran
CC = gcc
CXX = g++

all: fortran_calling_c_max.exe c_calling_cpp.exe

clean:
	rm -f *.o *.exe *.so

fortran_calling_c_max.exe: fortran_calling_c_max.o max.o
	${FC} fortran_calling_c_max.o max.o -o fortran_calling_c_max.exe

fortran_calling_c_max.o: fortran_calling_c_max.f90
	${FC} -c fortran_calling_c_max.f90

max.o: max.c
	${CC} -c max.c

c_calling_cpp.exe: c_calling_cpp.o libcppMin.so
	${CC} c_calling_cpp.o -L. -lcppMin -o c_calling_cpp.exe

c_calling_cpp.o: c_calling_cpp.c cppMin.hpp
	${CC} -c c_calling_cpp.c

libcppMin.so: cppMin.cpp cppMin.hpp
	${CXX} -fPIC -shared cppMin.cpp -o libcppMin.so