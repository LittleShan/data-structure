#include <stdio.h>
#include <stdlib.h>

#include "link.h"

/* 显示菜单 */
void display_menu();

int main(int argc, char *argv[])
{
	char menu_id;

	/* 初始化 */
	init_link();

	while (1) {
		display_menu();

		menu_id = getchar();

		switch(menu_id) {
			case '0':
				printf("退出程序\n");
				exit(0);
				break;
			case '1':
				create_link();
				break;
			case '2':
				display();
				break;
			case '3':
				get_element();
				break;
			case '4':
				get_position();
				break;
			case '5':
				insert_on_pos();
				break;
			case '6':
				delete_on_pos();
				break;
			case '7':
				destroy_link();
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

	puts("*************单链表*************");
	puts("*                              *");
	puts("*         1)创建单链表         *");
	puts("*         2)查看单链           *");
	puts("*         3)按结点位置查找     *");
	puts("*         4)按元素查找         *");
	puts("*         5)链表插入新元素     *");
	puts("*         6)删除链表元素       *");
	puts("*         7)销毁链表           *");
	puts("*         0)退出               *");
	puts("*                              *");
	puts("********************************");
}

