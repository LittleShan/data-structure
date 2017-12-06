#include <stdio.h>
#include <stdlib.h>
#include "threaded_binary_tree.h"

ThrBiTree prior = NULL;

/**
 * pause the program
 */
void time_out(const char *str, ...)
{
	char ch;
	
	puts(str);
	while ((ch = getchar()) != '\n' && ch != EOF);
	getchar();
}

/**
 * create a binary tree
 */
void create_bitree(ThrBiTree *T)
{
	char c;

	setbuf(stdin, NULL);
	fflush(stdin);
	scanf("%c", &c);

	if ('#' == c) {
		*T = NULL;
	} else {
		*T = (ThrBiTree)malloc(sizeof(Node));
		if (!(*T)) {
			perror("malloc error");
			exit(0);
		}

		(*T)->data = c;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;

		create_bitree(&(*T)->lchild);
		create_bitree(&(*T)->rchild);
	}
}

/**
 * Become threaded binary tree by Inorder traversal
 */
void in_thread(ThrBiTree T)
{
	if (T) {
		in_thread(T->lchild);

		if (!T->lchild) {
			T->ltag = Thread;
			T->lchild = prior;
		}

		if (prior && !prior->rchild) {
			prior->rtag = Thread;
			prior->rchild = T;
		}
		prior = T;

		in_thread(T->rchild);
	}
}

/**
 * In order traversal
 */
void in_order_traversal(ThrBiTree T)
{
	while (T) {
		while (T->ltag == Link) {
			T = T->lchild;
		}
		printf("%c", T->data);

		while (T->rtag == Thread && T->rchild != NULL) {
			T = T->rchild;
			printf("%c", T->data);
		}

		T = T->rchild;
	}
}
