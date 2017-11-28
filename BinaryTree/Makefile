all : a.out

a.out : main.c binary_tree.o stack.o
	gcc -g main.c binary_tree.o stack.o -o a.out
binary_tree.o : binary_tree.c
	gcc -c -g binary_tree.c -o binary_tree.o
stack.o : stack.c
	gcc -c -g stack.c -o stack.o

clean:
	rm -f a.out binary_tree.o stack.o
