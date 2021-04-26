CC=gcc
CFLAGS=-lm

windower: windower.o
	$(CC) -o windower windower.o $(CFLAGS)
	
clean:
	rm -f windower *.o windows.h