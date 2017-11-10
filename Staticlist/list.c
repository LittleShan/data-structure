#include <stdio.h>
#include "list.h"

/**
 * 暂停程序
 */
void time_out(const char *str, ...)
{
	puts(str);

	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	getchar();
}

/* 插入新结点接口 */
int insert_list_on_pos(List *L, int pos, ElemType e);

/**
 * 初始化静态链表
 */
void init_list(List *L)
{
	int i;

	/* 创建备用链表 */
	for (i = 0; i < SIZE; i++) {
		L[i].cur = i + 1;
	}
	L[SIZE - 1].cur = 0;

	/* 数据链表的结点个数 */
	L[0].data = 0;
}

/**
 * 创建静态链表
 */
void create_list(List *L)
{
	int n;	/* 结点个数 */
	int e;	/* 数据 */
	int i;	/* 控制循环的标量 */

	int result;

	printf("请输入元素个数(1~%d范围内)：", SIZE - 2);
	setbuf(stdin, NULL);
	scanf("%d", &n);
	if (n < 1 || n > (SIZE - 2)) {
		time_out("输入错误，按Enter键退出...");
		return;
	}

	printf("请输入%d个整数，空格隔开，Enter键结束：", n);
	for (i = 1; i <= n; i++) {
		setbuf(stdin, NULL);
		scanf("%d", &e);

		result = insert_list_on_pos(L, i, e);
		if (!result) {
			time_out("链表已满，按Enter键退出...");
			return;
		}
	}

	time_out("静态链表创建成功，按Enter键返回...");
}

/**
 * 插入链表
 */
void insert_list(List *L)
{
	int pos;  /* 插入的位置 */
	int e;    /* 插入的数据 */
	int i, p, q;

	if (L[0].data >= SIZE - 2) {
		time_out("链表已满，按Enter键返回...");
		return;
	}

	printf("请输入要插入的位置(1~%d范围内)：", L[0].data);
	setbuf(stdin, NULL);
	scanf("%d", &pos);

	if (pos < 1 || pos > L[0].data) {
		time_out("输入有误，按Enter键退出...");
		return;
	}

	printf("请输入要插入的数据：");
	setbuf(stdin, NULL);
	scanf("%d", &e);

	/* 找到要插入的结点位置 */
	for (i = 1, p = SIZE - 1; i < pos; i++) {
		p = L[p].cur;
	}

	q = malloc_space(L);
	if (q) {
		L[q].data = e;

		L[q].cur = L[p].cur;
		L[p].cur = q;
		
		L[0].data += 1;

		time_out("插入成功，按Enter键返回...");
	} else {
		time_out("链表已满，按Enter键返回...");
	}
}

/**
 * 插入新结点
 *
 * @param L 静态链表
 * @param pos 插入的位置
 * @param e 插入的数据
 * @return int
 */
int insert_list_on_pos(List *L, int pos, ElemType e)
{
	int k = SIZE - 1;

	int l;

	/* 申请空间，返回存放数据的下标 */
	int p = malloc_space(L);

	if (p) {
		L[p].data = e;

		/* 查找数据链表(未插入新结点前)的尾结点下标 */
		for (l = 1; l <= pos - 1; l++) {
			k = L[k].cur;
		}

		L[p].cur = L[k].cur;	/* 数据链表的尾节点的下标设为0 */
		L[k].cur = p;		/* 尾结点(未插入新结点前)的游标指向新结点 */

		L[0].data += 1;	/* 数据链表结点数+1 */

		return 1;
	}

	return 0;
}

/**
 * 遍历静态链表
 */
void display_list(List *L)
{
	int p = SIZE - 1;
	int i;

	if (L[0].data == 0) {
		time_out("静态链表为空，按Enter键返回...");
		return;
	}

	printf("静态链表元素：");
	while (L[p].cur) {
		i = L[p].cur;
		printf("%d ", L[i].data);
		p = i;
	}
	printf("\n");

	time_out("按Enter键返回...");
}

/**
 * 删除链表
 */
void delete_list(List *L)
{
	int e;	/* 要删除的元素 */
	int prev;  /* 被删除结点的前一个结点的位置 */
	int p;

	if (L[0].data == 0) {
		time_out("静态链表为空，按Enter键返回...");
		return;
	}

	printf("请输入要删除的元素：");
	scanf("%d", &e);

	prev = p = L[SIZE - 1].cur;

	/* 找到要删除的结点位置 */
	while(L[p].data != e) {
		prev = p;

		p = L[p].cur;
		if (p == 0) {
			time_out("链表中没有此元素，按Enter键退出...");
			return;
		}
	}

	/* 删除结点 */
	L[prev].cur = L[p].cur;

	/* 释放结点 */
	free_space(L, p);

	L[0].data -= 1;
	
	time_out("删除元素成功，按Enter返回...");
}

/**
 * 分配空间
 * 若备用链表非空，则返回分配的结点下标，否则返回0
 */
int malloc_space(List *L)
{
	int i = L[0].cur;

	if (L[0].cur) {
		L[0].cur = L[i].cur;
	}

	return i;
}

/**
 * 释放结点
 */
void free_space(List *L, int p)
{
	/* 把被删除的结点插入到备用链表的表头 */
	L[p].cur = L[0].cur;
	L[0].cur = p;
}
