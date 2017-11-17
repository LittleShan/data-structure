#ifndef _QUEUE_H
#define _QUEUE_H

#define MAXSIZE 10

typedef int ElemType;

/* queue struct */
typedef struct
{
	ElemType data[MAXSIZE];	/* data */
	int front;	/* Head pointer */
	int rear;	/* Tail pointer */
}Queue;

/* Pause the program */
void time_out(const char *str, ...);

/* Initialize queue */
Queue *init_queue();

/* In the queue */
void in_queue(Queue *q);

/* Out of the queue */
void out_queue(Queue *q);

/* Whether is full */
int full_queue(Queue *q);

/* Whether is empty */
int empty_queue(Queue *q);

#endif
