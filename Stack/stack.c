#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * Pause the program
 */
void time_out(const char *str, ...)
{
	char ch;

	puts(str);

	while ((ch = getchar()) != '\n' && ch != EOF);

	getchar();
}

/**
 * Initialize the stack
 */
Stack *init_stack()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));

	if (!s) {
		perror("malloc error");
		exit(1);
	}

	s->top = -1;

	return s;
}

/**
 * Push the stack
 */
void push(Stack *s)
{
	ElemType e;

	if (s->top == MAXSIZE - 1) {
		time_out("Full stack, press 'Enter' to return...");
		return;
	}

	printf("Plase input a element: ");
	scanf("%d", &e);

	s->top++;
	s->data[s->top] = e;

	time_out("\nSuccessful to push the stack, press 'Enter' to return...");
}

/**
 * Pop stakc
 */
void pop(Stack *s)
{
	if (s->top == -1) {
		time_out("Empty stack, press 'Enter' to return...");
		return;
	}

	printf("Top element：");
	printf("%d\n", s->data[s->top]);

	s->top--;

	time_out("press 'Enter' to return...");
}

void push_stack(Stack *s, ElemType e)
{
	if (s->top == MAXSIZE - 1) {
		time_out("Full stack, press 'Enter to return...'");
		return;
	}

	s->top++;
	s->data[s->top] = e;
}

void pop_stack(Stack *s)
{

	if (s->top == -1) {
		return;
	}

	printf("%d", s->data[s->top]);
	s->top--;
}

/**
 * Decimal to binary
 */
void decimal_to_binary()
{
	ElemType decimal;

	/* Initiazile a stack */
	Stack *s = (Stack *)malloc(sizeof(Stack));
	if (!s) {
		perror("malloc error");
		exit(0);
	}
	s->top = -1;

	/* Input a element */
	printf("Input a element: ");
	setbuf(stdin, NULL);
	scanf("%d",&decimal);

	/* Push the stack */
	while (decimal/2) {
		push_stack(s, decimal % 2);
		decimal = decimal/2;
	}
	push_stack(s, decimal % 2);

	/* Pop stack */
	printf("Result: ");
	while (s->top != -1) {
		pop_stack(s);
	}
	printf("\n");
	
	time_out("Press 'Enter' to return...");
}
