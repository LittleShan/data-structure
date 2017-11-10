all : a.out

a.out : main.c list.o
	gcc -g main.c list.o -o a.out
list.o : list.c
	gcc -c -g list.c -o list.o

clean:
	rm -f a.out list.o
