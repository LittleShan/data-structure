all : seqlist

seqlist : main.c seqlist.o
	gcc -g main.c seqlist.o -o seqlist
seqlist.o : seqlist.c
	gcc -c -g seqlist.c -o seqlist.o

clean:
	rm -f seqlist seqlist.o
