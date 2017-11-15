#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/**
 * 暂停程序
 */
void time_out(const char *str, ...) 
{
	char ch;

	puts(str);
	
	while ((ch = getchar()) != '\n' && ch != EOF);

	getchar();
}

/**
 * 链表初始化
 */
DuLinkList *init_linklist()
{
	DuLinkList *L;

	L = (DuLinkList *)malloc(sizeof(DuLinkList));
	if (!L) {
		perror("malloc error");
		exit(1);
	}

	L->data = 0;	/* 存储链表结点个数 */
	L->prior = NULL;
	L->next = NULL;

	return L;
}

/**
 * 判断链表是否为空
 */
int is_empty(DuLinkList *L)
{
	if (L->data < 1) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * 创建双向链表
 */
void create_linklist(DuLinkList *L)
{
	int n;		/* 结点个数 */
	ElemType e;	/* 结点数据 */
	int i;		/* 控制循环的标量 */

	DuLinkList *q, *p;

	q = L;	/* 指向头结点 */

	printf("请输入要创建的结点个数：");
	setbuf(stdin, NULL);
	scanf("%d", &n);

	printf("请输入%d个整数，空格隔开，按Enter键结束：", n);
	for (i = 1; i <= n; i++) {
		setbuf(stdin, NULL);
		scanf("%d", &e);

		p = (DuLinkList *)malloc(sizeof(DuLinkList));
		if (!p) {
			perror("malloc error");
			exit(1);
		}

		p->data = e;
		p->prior = NULL;
		p->next = NULL;

		q->next = p;
		p->prior = q;

		q = q->next;

		L->data += 1;
	}

	time_out("创建双向链表成功，按Enter键返回...");
}

/**
 * 遍历链表
 */
void display_linklist(DuLinkList *L)
{
	DuLinkList *p;

	if (is_empty(L)) {
		time_out("链表为空，按Enter返回...");
		return;
	}

	p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	time_out("按Enter键返回...");
}

/**
 * 插入新结点
 */
void insert_linklist(DuLinkList *L)
{
	DuLinkList *tmp, *p;

	int pos;
	ElemType e;
	int i;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	printf("请输入要插入的位置(1~%d范围内)：", L->data);
	setbuf(stdin, NULL);
	scanf("%d", &pos);
	
	if (pos < 0 || pos > L->data) {
		time_out("输入有误，按Enter键退出...");
		return;
	}

	printf("请输入数据：");
	setbuf(stdin, NULL);
	scanf("%d", &e);

	tmp = (DuLinkList *)malloc(sizeof(DuLinkList));
	if (!tmp) {
		perror("malloc error");
		exit(1);
	}
	tmp->data = e;
	tmp->prior = NULL;
	tmp->next = NULL;

	p = L->next;
	/* 找到要插入的位置的前一个结点 */
	for (i = 1; i < pos - 1; i++) {
		p = p->next;
	}

	/* 在表头插入 */
	if (pos == 1) {
		p->prior = tmp;
		tmp->next = p;
		L->next = tmp;
		tmp->prior = L;
	} else {
		p->next->prior = tmp;
		tmp->next = p->next;
		p->next = tmp;
		tmp->prior = p;
	}
	L->data += 1;

	time_out("插入结点成功，按Enter键返回...");
}

/**
 * 删除结点
 */
void delete_linklist(DuLinkList *L)
{
	DuLinkList *q, *p;

	int pos;
	int i;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	printf("请输入要输出要删除结点的位置(1~%d范围内)：", L->data);
	setbuf(stdin, NULL);
	scanf("%d", &pos);

	if (pos < 0 || pos > L->data) {
		time_out("输入有误，按Enter键退出...");
		return;
	}

	p = L->next;
	q = p;

	/* 找到要删除结点的位置 */
	for (int i = 1; i < pos; i++) {
		q = p;	/* 前一个结点的位置 */
		p = p->next;
	}

	/* 删除第一个结点 */
	if (pos == 1) {
		L->next = p->next;
		p->next->prior = L;
		q = NULL;
	} else {
		q->next = p->next;
		p->next->prior = q;
	}
	free(p);
	L->data -= 1;

	time_out("删除结点成功，按Enter键返回...");
}

/**
 * 销毁链表
 */
void destroy_linklist(DuLinkList *L)
{
	DuLinkList *q, *p;

	if (is_empty(L)) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	p = L;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}

	time_out("销毁链表成功，按Enter键退出...");
	exit(0);
}
