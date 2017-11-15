#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int ElemType;

/* 双向链表结构体 */
typedef struct _DuLinkList
{
	ElemType data;
	struct _DuLinkList *prior, *next;
}DuLinkList;

/* 暂停程序 */
void time_out(const char *str, ...);

/* 链表初始化 */
DuLinkList *init_linklist();

/* 判断链表是否为空 */
int is_empty(DuLinkList *L);

/* 创建链表 */
void create_linklist(DuLinkList *L);

/* 遍历链表 */
void display_linklist(DuLinkList *L);

/* 插入结点 */
void insert_linklist(DuLinkList *L);

/* 删除结点 */
void delete_linklist(DuLinkList *L);

/* 销毁链表 */
void destroy_linklist(DuLinkList *L);

#endif
