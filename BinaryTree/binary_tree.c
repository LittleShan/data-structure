#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "stack.h"
#include "queue.h"

/**
 * Pause the program
 */
void time_out(const char *str, ...)
{
	char ch;

	puts(str);
	while ((ch = getchar()) != EOF && ch != '\n');
	getchar();
}

/**
 * create a binary tree
 */
void create_btree(BiTree *T)
{
	char c;

	setbuf(stdin, NULL);
	fflush(stdin);
	scanf("%c", &c);

	if ('#' == c) {
		*T = NULL;
	} else {
		*T = (BiTree)malloc(sizeof(Node));
		if (!(*T)) {
			perror("malloc error");
			exit(1);
		}

		(*T)->data = c;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;

		create_btree(&(*T)->lchild);
		create_btree(&(*T)->rchild);
	}
}

/**
 * Preorder traversal(recursive)
 */
void pre_order_traversal_recursive(BiTree T)
{
	if (T) {
		printf("%c", T->data);
		pre_order_traversal_recursive(T->lchild);
		pre_order_traversal_recursive(T->rchild);
	}
}

/** 
 * Inorder to traversal(recursive)
 */
void in_order_traversal_recursive(BiTree T)
{
	if (T) {
		in_order_traversal_recursive(T->lchild);
		printf("%c", T->data);
		in_order_traversal_recursive(T->rchild);
	}
}

/**
 * Postorder traversal(recursive)
 */
void post_order_traversal_recursive(BiTree T)
{
	if (T) {
		post_order_traversal_recursive(T->lchild);
		post_order_traversal_recursive(T->rchild);
		printf("%c", T->data);
	}
}

/**
 * Preorder traversal(non-recursive)
 */
void pre_order_traversal(BiTree T)
{
	BiTree stack[20] = {0};
	BiTree p;

	push(stack, T);

	while (top != -1) {
		p = get_top(stack);

		pop();

		while (p) {
			printf("%c", p->data);

			if (p->rchild) {
				push(stack, p->rchild);
			}

			p = p->lchild;
		}
	}
}

/**
 * Inorder traversal(non-recursive)
 */
void in_order_traversal(BiTree T)
{
	BiTree stack[20] = {0};
	BiTree p;

	push(stack, T);

	while (top != -1) {
		while (p = get_top(stack)) {
			push(stack, p->lchild);
		}

		pop();

		if (top != -1) {
			p = get_top(stack);
			pop();
			printf("%c", p->data);
			push(stack, p->rchild);
		}
	}
}

/**
 * Postorder travesal(non-recursive)
 */
void post_order_traversal(BiTree T)
{
	Stack s[20] = {0};
	Stack sdata;
	int tag;
	
	BiTree p;

	p = T;
	while (p || top != -1) {
		while (p) {
			sdata.p = p;
			sdata.tag = 0;
			post_push(s, sdata);
			p = p->lchild;
		}

		sdata = s[top];
		pop();

		p = sdata.p;
		tag = sdata.tag;

		if (tag == 0) {
			sdata.p = p;
			sdata.tag = 1;
			post_push(s, sdata);
			p = p->rchild;
		} else {
			printf("%c", p->data);
			p = NULL;
		}
	}
}

/**
 * level_traversal
 */
void level_traversal(BiTree T)
{
	BiTree queue[20] = {0};	/* Sequential queue */
	BiTree p;

	in_queue(queue, T);	/* The root in the queue */

	while (front < rear) {
		p = out_queue(queue);
		printf("%c", p->data);

		/* left child and right in the queue */
		if (p->lchild != NULL) {
			in_queue(queue, p->lchild);
		}
		if (p->rchild != NULL) {
			in_queue(queue, p->rchild);
		}
	}
}
