FC = gfortran
CXX = g++

all: main.exe

clean:
	rm -f *.o *.exe *.so

main.exe: main.o libcppMin.so
	${FC} main.o -L. -lcppMin -o main.exe

main.o: main.f90
	${FC} -c main.f90

libcppMin.so: cppMin.cpp cppMin.hpp
	${CXX} -fPIC -shared cppMin.cpp -o libcppMin.so
