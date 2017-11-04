#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "link.h"

/**
 * 暂停程序
 * @param str 程序暂停时显示的字符串，可以包含格式控制符
 * @param ... 变长参数
 */
void time_out(const char *str, ...)
{
	puts(str);

	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	getchar();
}


/**
 * 遍历单链表
 */
void display()
{
	if (Header.num < 1) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	Link *p = Header.link;

	printf("单链表元素：");
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	time_out("按Enter返回...");
}

/**
 * 初始化单链表
 */
void init_link()
{
	Header.num = 0;
	Header.link = NULL;
}

/**
 * 创建单链表
 */
void create_link()
{
	if (Header.num > 0) {
		time_out("链表不为空，请先销毁再创建新的链表，按Enter键返回...");
		return;
	}

	int n;	/* 单链表结点个数*/
	int e;	/* 结点的值 */

	/* q指向表头 */
	Link *q = Header.link;

	printf("请输入创建的结点个数：\n");
	scanf("%d", &n);

	printf("请输入%d个整数，用空格隔开，回车键结束\n", n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", &e);

		Link *p = (Link *)malloc(sizeof(Link));
		if (!p) {
			time_out("内存分配失败，按Enter键返回...");
			return;
		}

		p->data = e;
		p->next = NULL;

		/* 链表第一个结点 */
		if (q  == NULL) {
			Header.link = p;
		} else {
			q->next = p;
		}
		q = p;

		Header.num++;
	}

	time_out("创建链表成功，按Enter键返回...");
}

/**
 * 获取单链表中第pos个结点的元素
 */
void get_element()
{
	if (Header.num < 1) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	int pos;  /* 要查找结点的位置 */

	Link *p = Header.link;  /* 头指针 */

	printf("请输入结点位置(范围1~%d)：", Header.num);
	while (1) {
		scanf("%d", &pos);
		if (pos < 0 || pos > Header.num) {
			printf("输入有误，请重新输入结点位置\n");
			continue;
		}
		break;
	}

	int i = 1;
	
	while(p && i < pos) {
		++i;
		p = p->next;
	}

	printf("结点位置：%d，元素：%d\n", pos, p->data);

	time_out("按Enter键返回...");
}

/**
 * 根据元素查找位置
 */
void get_position()
{
	if (Header.num < 1) {
		time_out("单链表为空，按Enter键返回...");
		return;
	}

	int pos = 0;
	int e;

	Link *p = Header.link;

	printf("请输入要查找的元素：");
	scanf("%d", &e);
	while (p->next) {
		++pos;

		if (e == p->data) {
			break;
		}

		p = p->next;
	}

	if (e != p->data) {
		time_out("您查找的元素不存在，按Enter键返回...");
		return;
	}

	printf("元素：%d，在单链表第一次出现的位置：%d\n", e, pos);

	time_out("按Enter键返回...");
}

/**
 * 在第n个位置插入元素
 */
void insert_on_pos()
{
	if (Header.num < 1) {
		time_out("单链表为空，按Enter键返回...");
		return;
	}

	int pos;  /* 插入的位置 */
	int e;    /* 插入的元素 */
	int i;    /* 记录链表的位置 */

	printf("请输入一个位置(1~%d范围内)：", Header.num);
	while(1) {
		scanf("%d", &pos);
		if (pos < 1 || pos > Header.num) {
			printf("输入的位置不合法，请重新输入");
			continue;
		}
		break;
	}

	printf("请输入元素的值：");
	scanf("%d", &e);

	/* p指向链表表头 */
	Link *p = Header.link;

	for (i = 1; i < pos; i++) {
		p = p->next;
	}

	Link *q = (Link *)malloc(sizeof(Link));
	q->data = e;
	q->next = p->next;
	p->next = q;

	Header.num++;

	time_out("插入成功，按Enter键返回...");
}

/**
 * 删除第n个结点
 */
void delete_on_pos()
{
	if (Header.num < 1) {
		time_out("链表为空，按Enter键返回...");
		return;
	}

	int pos;
	int i;
	int e;

	printf("请输入结点的位置(1~%d范围内)：", Header.num);
	while(1) {
		scanf("%d", &pos);
		if (pos < 1 || pos > Header.num) {
			printf("输入的位置不合法，请重新输入：");
			continue;
		}
		break;
	}

	Link *q, *p;

	q = p = Header.link;

	for (i = 1; i < pos; i++) {
		/* 指向要删除结点的前驱元素 */
		q = p;
		p = p->next;
	}

	q->next = p->next;
	e = p->data;
	free(p);

	Header.num--;

	printf("结点位置：%d，元素：%d，删除成功!\n", pos, e);

	time_out("按Enter键返回...");
}

/**
 * 销毁链表
 */
void destroy_link()
{
	if (Header.num < 1) {
		time_out("单链表为空，按Enter返回...");
		return;
	}

	Link *q, *p;

	q = Header.link;

	while (q) {
		p = q;
		q = q->next;

		free(p);
	}

	Header.link = NULL;
	Header.num = 0;

	time_out("销毁链表成功，按Enter返回...");
}
