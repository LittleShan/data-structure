#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int top = -1;

/**
 * Initialize stack
 */
BiTree *init_stack()
{
	BiTree *stack = (BiTree *)malloc(sizeof(Node));
	if (!stack) {
		perror("malloc error");
		exit(1);
	}

	return stack;
}

/**
 * Push stack
 */
void push(BiTree *stack, BiTree T)
{
	stack[++top] = T;
}

/**
 * Pop stack
 */
void pop()
{
	if (top == -1) {
		return;
	}

	top--;
}

/**
 * Get the top element
 */
BiTree get_top(BiTree *stack)
{
	return stack[top];
}

/**
 * Push the stack(Postorder)
 */
void post_push(Stack *s, Stack sdata)
{
	s[++top] = sdata;
}
