#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
 * Initialize queue
 */
Queue *init_queue()
{
	Queue *q;

	q = (Queue *)malloc(sizeof(Queue));
	if (!q) {
		perror("malloc error");
		exit(1);
	}

	q->front = q->rear = 0;

	return q;
}

/**
 * In the queue
 */
void in_queue(Queue *q)
{
	ElemType e;

	if (full_queue(q)) {
		time_out("Full queue, press 'Enter' to return...");
		return;
	}

	printf("Input a data: ");
	setbuf(stdin, NULL);
	scanf("%d", &e);

	q->data[q->rear] = e;
	q->rear++;

	time_out("Successful to in the queue,press 'Enter' to return...");
}

/**
 * Out of the queue
 */
void out_queue(Queue *q)
{
	if (empty_queue(q)) {
		time_out("Empty queue,press 'Enter' to return...");
		return;
	}

	printf("Data: %d\n", q->data[q->front]);
	q->front++;

	time_out("Press 'Enter' to return...");
}

/**
 * Whether is full
 */
int full_queue(Queue *q)
{
	if (((q->rear + 1) % MAXSIZE) == q->front) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * Whether is empty
 */
int empty_queue(Queue *q)
{
	if (q->front == q->rear) {
		return 1;
	} else {
		return 0;
	}
}
