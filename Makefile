# no clue how to make a makefile tbh 

LIBS=	-lm -lraylib -lraygui

all: prime-numbers

prime-numbers: plotter.c primes.c
	cc $^ ${LIBS} -o $@

run:
	./prime-numbers

clean:
	rm -f prime-numbers *.o
