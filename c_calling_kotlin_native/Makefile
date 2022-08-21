KOTLINC = kotlinc-native
CC = gcc

all: main.exe

clean:
	rm -rf *.o *.exe *.dylib *.dSYM c_calling_kotlin_native_api.h *.Contents

main.exe: main.o
	${CC} main.o -o main.exe -lc_calling_kotlin_native -L.

main.o: main.c c_calling_kotlin_native_api.h
	${CC} -c main.c

c_calling_kotlin_native_api.h: c_calling_kotlin_native.kt
	${KOTLINC} c_calling_kotlin_native.kt -produce dynamic -o c_calling_kotlin_native.dylib
