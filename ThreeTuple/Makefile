all : a.out

a.out : main.c triple.o
	gcc -g main.c triple.o -o a.out
triple.o : triple.c
	gcc -c -g triple.c -o triple.o

clean:
	rm -f a.out triple.o
