#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void display_menu();

int main(int argc, char *argv[])
{
	char menu_id;

	List L[SIZE];

	/* 初始化静态链表，创建备用链表 */
	init_list(L);

	while (1) {
		display_menu();

		menu_id = getchar();

		switch(menu_id) {
			case '1':
				create_list(L);
				break;
			case '2':
				display_list(L);
				break;
			case '3':
				insert_list(L);
				break;
			case '4':
				delete_list(L);
				break;
			case '0':
				printf("退出程序\n");
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

	puts("*************静态链表*************");
	puts("*                                *");
	puts("*         1)创建静态链表         *");
	puts("*         2)查看链表             *");
	puts("*         3)插入新元素           *");
	puts("*         4)删除链表元素         *");
	puts("*         0)退出                 *");
	puts("*                                *");
	puts("**********************************");
}


