all : a.out

a.out : main.c threaded_binary_tree.o
	gcc -g main.c threaded_binary_tree.o -o a.out
threaded_binary_tree.o : threaded_binary_tree.c
	gcc -c -g threaded_binary_tree.c -o threaded_binary_tree.o

clean:
	rm -f a.out threaded_binary_tree.o
