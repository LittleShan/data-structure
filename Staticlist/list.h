#ifndef _LIST_H
#define _LIST_H

#define SIZE 6

typedef int ElemType;

/* 链表结构 */
typedef struct
{
	ElemType data;
	int cur;
}List;

/* 暂停程序 */
void time_out(const char *str, ...);

/* 分配空间 */
int malloc_space(List *L);

/* 释放空间 */
void free_space(List *L, int pos);

/* 初始化静态链表 */
void init_list(List *L);

/* 创建静态链表 */
void create_list(List *L);

/* 插入链表 */
void insert_list(List *L);

/* 删除结点 */
void delete_list(List *L);

/* 遍历链表 */
void display_list(List *L);

#endif
