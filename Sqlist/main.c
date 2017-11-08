#include <stdio.h>
#include <stdlib.h>

#include "seqlist.h"

/* 显示操作菜单 */
void display_menu();

int main(int argc, char *argv[])
{
	char menu_id;

	SeqList *L;

	/* 初始化顺序表 */
	L = init_seqlist();

	while (1) {
		display_menu();

		menu_id = getchar();

		switch (menu_id) {
			case '1':
				create_seqlist(L);
				break;
			case '2':
				display_seqlist(L);
				break;
			case '3':
				get_elem(L);
				break;
			case '4':
				insert_seqlist(L);
				break;
			case '5':
				delete_seqlist(L);
				break;
			case '0':
				printf("退出程序");
				exit(0);
				break;
			default:
				break;
		}
	}

	return 0;
}

/**
 * 显示菜单
 */
void display_menu()
{
	system("clear");

	puts("*************顺序表*************");
	puts("*                              *");
	puts("*         1)创建顺序表         *");
	puts("*         2)查看顺序表         *");
	puts("*         3)查找某个元素       *");
	puts("*         4)插入元素           *");
	puts("*         5)删除元素           *");
	puts("*         0)退出               *");
	puts("*                              *");
	puts("********************************");
}
