all : a.out

a.out : main.c queue.o
	gcc -g main.c queue.o -o a.out
queue.o : queue.c
	gcc -c -g queue.c -o queue.o

clean:
	rm -f a.out queue.o
