all : a.out

a.out : main.c linklist.o
	gcc -g main.c linklist.c -o a.out

linklist.o : linklist.c
	gcc -c -g linklist.c -o linklist.o

clean:
	rm -f a.out linklist.o
