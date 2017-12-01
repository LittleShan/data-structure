all : a.out

a.out : main.c binary_tree.o stack.o queue.o
	gcc -g main.c binary_tree.o stack.o queue.o -o a.out
binary_tree.o : binary_tree.c
	gcc -c -g binary_tree.c -o binary_tree.o
stack.o : stack.c
	gcc -c -g stack.c -o stack.o
queue.o : queue.c
	gcc -c -g queue.c -o queue.o

clean:
	rm -f a.out binary_tree.o stack.o queue.o
