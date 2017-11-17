#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void display_menu();

int main(int argc, char *argv[])
{
	char menu_id;

	Queue *q = init_queue();

	while (1) {
		display_menu();

		menu_id = getchar();

		switch (menu_id) {
			case '1':
				in_queue(q);
				break;
			case '2':
				out_queue(q);
				break;
			case '0':
				exit(0);
				break;
			default:
				break;
		}
	}

	return 0;
}

void display_menu()
{
	system("clear");

	puts("*************Circular Queue*************");
	puts("*                                      *");
	puts("*           1)In queue                 *");
	puts("*           2)Out of the queue         *");
	puts("*           0)Exit                     *");
	puts("*                                      *");
	puts("****************************************");
}
