CARGO = cargo
CC = gcc

all: main.exe

clean:
	rm -f *.o *.exe
	rm -rf target

main.exe: main.o libc_calling_rust
	${CC} main.o -o main.exe -lc_calling_rust -L./target/debug

main.o: main.c
	${CC} -c main.c

libc_calling_rust: src/lib.rs
	${CARGO} build
