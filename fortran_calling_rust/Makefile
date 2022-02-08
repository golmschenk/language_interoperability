FC = gfortran
CC = gcc
CARGO = cargo

all: main.exe

clean:
	rm -f *.o *.exe
	rm -rf target

main.exe: main.o libfortran_calling_rust
	${FC} main.o -o main.exe -lfortran_calling_rust -L./target/debug
	${CC} -c dummy.c

main.o: main.f90
	${FC} -c main.f90

libfortran_calling_rust: src/lib.rs
	${CARGO} build
