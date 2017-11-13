#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void display_menu();

int main(int argc, char *argv[])
{
	LinkList *L = init_linklist();

	char menu_id;

	while (1) {
		display_menu();

		menu_id = getchar();

		switch(menu_id) {
			case '1':
				create_linklist(L);
				break;
			case '2':
				display_linklist(L);
				break;
			case '3':
				insert_linklist(L);
				break;
			case '4':
				delete_linklist(L);
				break;
			case '5':
				destroy_linklist(L);
				break;
			case '6':
				joseph();
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

	puts("*************循环链表*************");
	puts("*                                *");
	puts("*         1)创建循环链表         *");
	puts("*         2)查看链表             *");
	puts("*         3)插入新结点           *");
	puts("*         4)删除结点             *");
	puts("*         5)销毁链表             *");
	puts("*         6)约瑟夫环问题         *");
	puts("*         0)退出                 *");
	puts("*                                *");
	puts("**********************************");
}

