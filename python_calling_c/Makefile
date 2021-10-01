CC = gcc

all: libcMultiply.so

clean:
	rm -f *.o *.exe *.so

libcMultiply.so: cMultiply.c cMultiply.h
	${CC} -fPIC -shared cMultiply.c -o libcMultiply.so