#ifndef _LINK_H
#define _LINK_H

/* 暂停程序 */
void time_out(const char *str, ...);

/* 数据类型 */
typedef int ElemType;

/* 单链表结构 */
typedef struct _Link
{
	ElemType data;		/* 数据 */
	struct _Link *next;	/* 指向后继元素 */
}Link;

/* 链表头结点 */
struct
{
	int num;	/* 结点个数 */
	Link *link;	/* 链表指针 */
}Header;

/* 单链表相关操作 */
void init_link();	/* 初始化链表 */
void create_link();	/* 创建链表 */
void display();		/* 遍历链表 */
void get_element();	/* 获取单链表第pos个结点中的元素 */
void get_position();	/* 获取某个结点的值在单链表中的位置 */
void insert_on_pos();	/* 在第n个位置插入元素*/
void delete_on_pos();	/* 删除链表元素 */
void destroy_link();	/* 销毁链表 */

#endif

