FC = gfortran
CC = gcc
CARGO = cargo

all: main.exe

clean:
	rm -f *.o *.exe
	rm -rf target

main.exe: main.o libfortran_calling_rust_with_dynamic_array_passing
	${FC} main.o -o main.exe -lfortran_calling_rust_with_dynamic_array_passing -L./target/debug
	${CC} -c dummy.c

main.o: main.f90
	${FC} -c main.f90

libfortran_calling_rust_with_dynamic_array_passing: src/lib.rs
	${CARGO} build
