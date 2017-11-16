all : a.out

a.out : main.c stack.o
	gcc -g main.c stack.o -o a.out
stack.o : stack.c
	gcc -c -g stack.c -o stack.o

clean:
	rm -f a.out stack.o
