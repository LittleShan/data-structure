#ifndef _SEQLIST_H
#define _SEQLIST_H

#define SIZE 5		/* 顺序表初始容量大小 */
#define INCREMENT 4	/* 扩容的大小 */

typedef int ElemType;	/* 数据类型 */

/* 顺序表结构体 */
typedef struct
{
	ElemType *elem;	/* 保存数据的数组 */
	int length;	/* 顺序表当前长度 */
	int size;	/* 分配的容量 */
}SeqList;

/* 暂停程序 */
void time_out(const char *, ...);

/* 初始化顺序表 */
SeqList *init_seqlist();

/* 创建顺序表 */
void create_seqlist(SeqList *L);

/* 查找某个下标的元素 */
void get_elem(SeqList *L);

/* 插入元素 */
void insert_seqlist(SeqList *L);

/* 删除元素 */
void delete_seqlist(SeqList *L);

/* 遍历顺序表 */
void display_seqlist(SeqList *L);

#endif
