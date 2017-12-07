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
 * create a doubly threaded binary tree
 */
void doubly_in_thread(ThrBiTree *h, ThrBiTree T)
{
	*h = (ThrBiTree)malloc(sizeof(Node));
	if (!(*h)) {
		perror("malloc error");
		exit(0);
	}

	(*h)->rchild = *h;
	(*h)->rtag = Link;

	if (!T) {
		(*h)->rchild = *h;
		(*h)->ltag = Link;
	} else {
		prior = *h;	/* pointer to first node */
		(*h)->lchild = T;
		(*h)->ltag = Link;

		in_thread(T);

		prior->rchild = *h;
		prior->rtag = Thread;
		(*h)->rchild = prior;
	}
}

/**
 * Inorder traversal start on forward direction
 */
void in_order_traversal_forward(ThrBiTree h)
{
	ThrBiTree p = h->lchild;

	while (p != h) {
		while (p->ltag == Link) {
			p = p->lchild;
		}
		printf("%c", p->data);

		while (p->rtag == Thread && p->rchild != h) {
			p = p->rchild;
			printf("%c", p->data);
		}

		p = p->rchild;
	}
}

/**
 * Inorder traversal start on reverse direction
 */
void in_order_traversal_reverse(ThrBiTree h)
{
	ThrBiTree p = h->rchild;

	while (p != h) {
		while (p->rtag == Link) {
			p = p->rchild;
		}
		printf("%c", p->data);

		while (p->ltag == Thread && p->lchild != h) {
			p = p->lchild;
			printf("%c", p->data);
		}

		p = p->lchild;
	}
}
