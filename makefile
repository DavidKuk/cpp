CC=g++ -o
CC2=g++
CFLAGS = -I.
MYLIB= libMyLibrary.so
LIBFLAG=g++ -shared -o

all:exe

exe: $(MYLIB) main.o
	$(CC2) main.o -L.  -lMyLibrary -o exe
	sudo mv libMyLibrary.so /usr/lib/
 
$(MYLIB): int_to_string.o string_to_int.o minus_and_dot.o position.o operation.o
	$(LIBFLAG) $(MYLIB) int_to_string.o string_to_int.o minus_and_dot.o position.o operation.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

int_to_string.o: int_to_string.cpp
	$(CC) int_to_string.o -fpic -c int_to_string.cpp $(CFLAGS)

string_to_int.o: string_to_int.cpp
	$(CC) string_to_int.o -fpic -c string_to_int.cpp $(CFLAGS)

minus_and_dot.o: minus_and_dot.cpp
	$(CC) minus_and_dot.o -fpic -c minus_and_dot.cpp $(CFLAGS)

position.o: position.cpp
	$(CC) position.o -fpic -c position.cpp $(CFLAGS)

operation.o: operation.cpp
	$(CC) operation.o -fpic -c operation.cpp $(CFLAGS)

.PHONY: clean

clean: 
	rm -rf *.o
