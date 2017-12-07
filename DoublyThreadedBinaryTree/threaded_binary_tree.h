#ifndef _THREADED_BINARY_TREE
#define _THREADED_BINARY_TREE

typedef char ElemType;

typedef enum
{
	Link,	// 0
	Thread	// 1
}Tag;

/* Threaded binary tree struct */
typedef struct _Node
{
	ElemType data;
	struct _Node *lchild, *rchild;
	Tag ltag, rtag;
}Node, *ThrBiTree;

/* pointer to the prior node */
extern ThrBiTree prior;

/* pause the program */
extern void time_out(const char *str, ...);

/* create a binary tree */
extern void create_bitree(ThrBiTree *T);

/* become threaded binary tree by in-order traversal */
extern void in_thread(ThrBiTree T);

/* create a doubly threaded binary tree */
extern void doubly_in_thread(ThrBiTree *h, ThrBiTree T);

/* inorder traversal start on forward direction */
extern void in_order_traversal_forward(ThrBiTree T);

/* inorder traversal start on reverse direction */
extern void in_order_traversal_reverse(ThrBiTree T);
#endif
