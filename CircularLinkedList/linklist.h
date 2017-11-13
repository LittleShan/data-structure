#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int ElemType;

/* 循环链表结构体 */
typedef struct _LinkList
{
	ElemType data;
	struct _LinkList *next;
}LinkList;

/* 暂停程序 */
void time_out(const char *str, ...);

/* 初始化链表 */
LinkList *init_linklist();

/* 判断链表是否为空 */
int is_empty(LinkList *L);

/* 创建链表 */
void create_linklist(LinkList *L);

/* 遍历链表 */
void display_linklist(LinkList *L);

/* 向链表中插入结点 */
void insert_linklist(LinkList *L);

/* 删除结点 */
void delete_linklist(LinkList *L);

/* 销毁链表 */
void destroy_linklist(LinkList *L);

#endif
