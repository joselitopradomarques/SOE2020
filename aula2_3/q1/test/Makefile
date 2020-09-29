# makefile

all: hello

hello: main.o ola.o
	gcc -o hello main.o ola.o
	
main.o: main.c ola.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic
	
ola.o: ola.c ola.h
	gcc -o ola.o ola.c -c -W -Wall -ansi -pedantic
	
clean:
	rm -rf *.o *~ hello
