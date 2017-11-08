#include <stdio.h>
#include <stdlib.h>

#include "seqlist.h"

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

/**
 * 初始化顺序表
 */
SeqList *init_seqlist()
{
	SeqList *L;

	L= (SeqList *)malloc(sizeof(SeqList));
	if (!L) {
		printf("内存分配失败\n");
		exit(1);
	}

	/* 申请SIZE个空间 */
	(*L).elem = (ElemType *)malloc(SIZE*sizeof(ElemType *));
	if (!(*L).elem) {
		printf("分配内存失败\n");
		exit(1);
	}

	(*L).length = 0;
	(*L).size = SIZE;

	return L;
}

/**
 * 创建顺序表
 */
void create_seqlist(SeqList *L)
{
	int elem_nums;	/* 元素个数 */
	int e;		/* 元素 */
	int i;

	printf("请输入元素的个数：");
	scanf("%d", &elem_nums);

	/* 判断元素个数是否超出容量，如果超出则进行扩容 */
	if (elem_nums > (*L).size) {
		(*L).elem = realloc((*L).elem, elem_nums*sizeof(ElemType));
		if (!(*L).elem) {
			printf("分配内存失败\n");
			exit(1);
		}

		(*L).size = elem_nums;
	}

	printf("请输入%d个整数，按Enter键结束\n", elem_nums);
	for (i = 0; i < elem_nums; i++) {
		scanf("%d", &e);
		(*L).elem[i] = e;
		(*L).length++;
	}

	time_out("创建顺序表成功，按Enter键返回...");
}

/**
 * 查找某个位置的元素
 */
void get_elem(SeqList *L)
{
	if ((*L).length < 1) {
		time_out("顺序表为空，按Enter键返回...");
		return;
	}

	int pos;

	printf("请输入要查找位置(1~%d范围内)：", (*L).length);
	scanf("%d", &pos);

	if (pos < 1 || pos > (*L).length) {
		time_out("输入错误，按Enter键退出...");
		return;
	}

	printf("位置：%d，元素：%d\n", pos, (*L).elem[pos -1]);
	
	time_out("查找成功，按Enter键返回...");
}

/**
 * 插入元素
 */
void insert_seqlist(SeqList *L)
{
	if ((*L).length < 1) {
		time_out("顺序表为空，请先创建顺序表...");
		return;
	}

	int pos;
	int e;

	printf("请输入要插入的位置(1~%d范围内)：", (*L).length);
	while (1) {
		scanf("%d", &pos);
		if (pos < 1 || pos > (*L).length) {
			printf("输入有误，重新输入");
		}
		break;
	}

	printf("请输入元素的值：");
	scanf("%d", &e);

	/* 判断是否需要扩容 */
	if ((*L).length > (*L).size) {
		(*L).elem = realloc((*L).elem, ((*L).length + 1)*sizeof(ElemType));
		(*L).size += 1;
	}

	int i;
	for (i = (*L).length - 1; i >= pos - 1; i--) {
		(*L).elem[i + 1] = (*L).elem[i];
	}
	(*L).elem[pos - 1] = e;
	(*L).length++;
	
	time_out("插入成功，按Enter键返回...");
}

/**
 * 删除顺序表
 */
void delete_seqlist(SeqList *L)
{
	if ((*L).length < 1) {
		time_out("顺序表为空，按Enter键返回...");
		return;
	}

	int pos;

	printf("请输入要删除的元素的位置(1~%d范围内)：", (*L).length);
	scanf("%d", &pos);

	if (pos < 1 || pos > (*L).length) {
		time_out("输入有误，按Enter键退出...");
		return;
	}

	int i;
	for (i = pos -1; i < (*L).length - 1; i++) {
		(*L).elem[i] = (*L).elem[i + 1];
	}
	(*L).length -= 1;

	time_out("删除成功，按Enter键返回...");
}

/**
 * 遍历顺序表
 */
void display_seqlist(SeqList *L)
{
	if ((*L).length < 1) {
		time_out("顺序表为空，按Enter键返回...");
		return;
	}
	
	int i;

	printf("顺序表元素：");
	for (i = 0; i < (*L).length; i++) {
		printf("%d ", (*L).elem[i]);
	}
	printf("\n");

	time_out("按Enter键返回...");
}
