#ifndef _STACK_H
#define _STACK_H

#define MAXSIZE 100

typedef int ElemType;

/* The stack struct */
typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}Stack;

/* Pause the program */
void time_out(const char *str, ...);

/* Initialize the stack */
Stack *init_stack();

/* Push stack */
void push(Stack *s);

/* Pop stack */
void pop(Stack *s);

/* Decimal to binary */
void decimal_to_binary();

#endif
