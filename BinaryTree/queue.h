#ifndef _QUEUE_H
#define _QUEUE_H

#include "binary_tree.h"

extern int front;
extern int rear;

/* In the queue */
void in_queue(BiTree *queue, BiTree T);

/* Out the queue */
BiTree out_queue(BiTree *queue);

#endif
