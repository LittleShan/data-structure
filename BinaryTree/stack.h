#ifndef _STACK_H
#define _STACK_H

#define SIZE 20

#include "binary_tree.h"

extern int top;

typedef struct
{
	BiTree p;
	int tag;  /* flage: 0 lchild 1 rchild */
}Stack;

/**
 * Initialize stack
 */
extern BiTree *init_stack();

/* Push stack */
extern void push(BiTree *stack, BiTree T);

/* Pop stack */
extern void pop();

/* Get the top element */
extern BiTree get_top(BiTree *stack);

/* Push stack(Postorder) */
extern void post_push(Stack *s, Stack sdata);

#endif
