#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/**
 * 暂停程序
 */
void time_out(const char *str, ...)
{
	puts(str);

	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);

	getchar();
}

/**
 * 初始化循环链表
 */
LinkList *init_linklist()
{
	LinkList *head;

	head = (LinkList *)malloc(sizeof(LinkList));
	if (!head) {
		printf("分配内存失败\n");
		exit(1);
	}

	head->data = 0;	/* 第一个结点的data用来存储链表的结点数 */
	head->next = head;

	return head;
}

/**
 * 判断链表是否为空
 */
int is_empty(LinkList *L)
{
	LinkList *h = L;

	if (h == h->next) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * 创建链表
 */
void create_linklist(LinkList *L)
{
	int nums;	/* 结点个数 */
	ElemType e;	/* 结点数据 */
	int i;		/* 控制循环的标量 */

	LinkList *p, *rear;

	rear = L;

	printf("请输入要创建的结点个数：");
	setbuf(stdin, NULL);
	scanf("%d", &nums);

	printf("请输入%d个整数，空格隔开，按Enter键结束：", nums);
	for (i = 1; i <= nums; i++) {
		setbuf(stdin, NULL);
		scanf("%d", &e);

		p = (LinkList *)malloc(sizeof(LinkList));
		p->data = e;
		p->next = NULL;
		rear->next = p;
		rear = rear->next;

		L->data += 1;	/* 链表的结点数+1 */
	}

	rear->next = L;	/* 首尾相连 */

	time_out("创建链表成功，按Enter键返回...");
}

/**
 * 遍历链表
 */
void display_linklist(LinkList *L)
{
	LinkList *h, *p;

	h  = L;
	p = h->next;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	while (p != h) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	time_out("按Enter键返回...");
}

/**
 * 向链表插入结点
 */
void insert_linklist(LinkList *L)
{
	int pos;	/* 插入结点位置 */
	ElemType e;	/* 结点数据 */
	int i;		/* 控制循环的标量 */

	LinkList *node, *p, *q;

	p = L->next;
	q = p;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	printf("请输入要插入的位置(1~%d范围内)：", L->data);
	scanf("%d", &pos);
	if (pos < 1 || pos > L->data) {
		time_out("输入有误，按Enter键退出...");
		return;
	}

	printf("请输入结点数据：");
	scanf("%d", &e);

	/* 找到插入位置的前一个结点 */
	for (i = 1; i < pos; i++) {
		q = p;
		p = p->next;
	}
	
	p = (LinkList *)malloc(sizeof(LinkList));
	if (!p) {
		printf("分配内存失败\n");
		exit(1);
	}

	p->data = e;
	p->next = q->next;
	q->next = p;

	L->data += 1;

	time_out("插入成功，按Enter键返回...");
}

/**
 * 删除结点
 */
void delete_linklist(LinkList *L)
{
	int pos; /* 要删除结点的位置 */
	int i;	 /* 控制循环的标量 */

	LinkList *p, *q;

	q = p = L->next;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键退出...");
		return;
	}

	printf("请输入要删除的结点位置(1~%d范围内)：", L->data);
	scanf("%d", &pos);

	if (pos < 1 || pos > L->data) {
		time_out("输入有误，按Enter键退出程序...");
		return;
	}

	/* 找到要删除结点的前一个结点 */
	for (i = 1; i < pos; i++) {
		q = p;
		p = p->next;
	}

	q->next = p->next;
	free(p);

	L->data -= 1;

	time_out("删除结点成功，按Enter键返回...");
}

/**
 * 销毁循环链表
 */
void destroy_linklist(LinkList *L)
{
	LinkList *h, *p, *q;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键退出...");
		return;
	}
	
	h = L;
	p = q = h->next;
	
	while(p != h) {
		q = p;
		p = p->next;
		free(q);
	}
	
	L->data = 0;
	h->next = h;	/* 首尾相连 */

	time_out("销毁链表成功，按Enter键返回...");
}
