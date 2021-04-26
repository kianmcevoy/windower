CC=gcc
CFLAGS=-lm

windower: windower.o
	$(CC) -o windower windower.o $(CFLAGS)
	
clean:
	rm -f *.o