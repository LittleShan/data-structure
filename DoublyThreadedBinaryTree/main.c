#include <stdio.h>
#include <stdlib.h>
#include "threaded_binary_tree.h"

/* display menu */
void display_menu();

int main(int argc, char *argv[])
{
	char menu_id;

	ThrBiTree T = NULL;
	ThrBiTree h = NULL;

	while (1) {
		display_menu();

		menu_id = getchar();

		switch(menu_id) {
			case '1':
				printf("Enter a string of Englist letter: ");
				create_bitree(&T);
				time_out("Success, press 'Enter' to return...");
				break;
			case '2':
				printf("Inthread...\n");
				doubly_in_thread(&h, T);
				time_out("Success, press 'Enter' to return...");
				break;
			case '3':
				printf("Result: ");
				in_order_traversal_forward(h);
				time_out("\nPress 'Enter' to return...");
				break;
			case '4':
				printf("Result: ");
				in_order_traversal_reverse(h);
				time_out("\nPress 'Enter' to return...");
				break;
			case '0':
				printf("Exit\n");
				exit(0);
			default:
				break;
		}
	}

	return 0;
}

void display_menu()
{
	system("clear");

	puts("**************Threaded Binary Tree***************");
	puts("*                                               *");
	puts("*        1)Create a binary tree                 *");
	puts("*        2)Doubly threaded                      *");
	puts("*        3)Forward direction traversal          *");
	puts("*        4)Reverse direction traversal          *");
	puts("*        0)Exit                                 *");
	puts("*                                               *");
	puts("*************************************************");
}
