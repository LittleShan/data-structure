all : link

link : main.c link.o
	gcc -g main.c link.o -o link
link.o : link.c
	gcc -c -g link.c -o link.o

clean:
	rm -f link link.o
