#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#define MAXSIZE 50

typedef char ElemType;

/* Binary tree struct */
typedef struct _Node
{
	ElemType data;
	struct _Node *lchild, *rchild;
}Node, *BiTree;

/* Pause the program */
extern void time_out(const char *str, ...);

/* Create a binary tree */
extern void create_btree(BiTree *T);

/* Preorder traversal(recursive) */
extern void pre_order_traversal_recursive(BiTree T);

/* In order to traverse(recursive) */
extern void in_order_traversal_recursive(BiTree T);

/* Post-order traversal(recursive) */
extern void post_order_traversal_recursive(BiTree T);

/* Preorder traversal(non-recursive) */
extern void pre_order_traversal(BiTree T);

/* In order traversal(non-recursive) */
extern void in_order_traversal(BiTree T);

/* Post-order traversal(non-recursive) */
extern void post_order_traversal(BiTree T);

#endif
