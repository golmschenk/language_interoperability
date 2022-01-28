FC = gfortran
CARGO = cargo

all: main.exe

clean:
	rm -f *.o *.exe
	rm -rf target

main.exe: main.o libc_calling_rust
	${FC} main.o -o main.exe -lc_calling_rust -L./target/debug

main.o: main.f90
	${FC} -c main.f90

libc_calling_rust: src/lib.rs
	${CARGO} build
