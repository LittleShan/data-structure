#include "queue.h"

int front = 0;
int rear = 0;

/**
 * In the queue
 */
void in_queue(BiTree *queue, BiTree T)
{
	queue[rear++] = T;
}

/**
 * Out the queue
 */
BiTree out_queue(BiTree *queue)
{
	return queue[front++];
}
