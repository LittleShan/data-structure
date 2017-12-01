#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

/* Display menu */
void display_menu();

int main(int argc, char *argv[])
{
	BiTree T = NULL;

	char menu_id;

	while (1) {
		display_menu();

		menu_id = getchar();

		switch (menu_id) {
			case '1':
				printf("Enter a string of English letters: ");
				create_btree(&T);
				time_out("Success,press 'Enter' to return...");
				break;
			case '2':
				printf("Result: ");
				pre_order_traversal_recursive(T);
				time_out("\nPress 'Enter' to return...");
				break;
			case '3':
				printf("Result: ");
				in_order_traversal_recursive(T);
				time_out("\nPress 'Enter' to return...");
				break;
			case '4':
				printf("Result: ");
				post_order_traversal_recursive(T);
				time_out("\nPress 'Enter' to return...");
				break;
			case '5':
				printf("Result: ");
				pre_order_traversal(T);
				time_out("\nPress 'Enter' to return...");
				break;
			case '6':
				printf("Result: ");
				in_order_traversal(T);
				time_out("\nPress 'Enter' to return...");
				break;
			case '7':
				printf("Result: ");
				post_order_traversal(T);
				time_out("\nPress 'Enter' to return...");
				break;
			case '8':
				printf("Result: ");
				level_traversal(T);
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

/**
 * Display menu
 */
void display_menu()
{
	system("clear");

	puts("*******************Binary Tree*******************");
	puts("*                                               *");
	puts("*        1)Create a binary tree                 *");
	puts("*        2)Preorder traversal(recursive)        *");
	puts("*        3)Inorder traversal(recursive)         *");
	puts("*        4)Postorder traversal(recursive)       *");
	puts("*        5)Preorder traversal(non-recursive)    *");
	puts("*        6)Inorder traversal(non-recursive)     *");
	puts("*        7)Postorder traversal(non-recursive)   *");
	puts("*        8)Level traversal                      *");
	puts("*        0)Exit                                 *");
	puts("*                                               *");
	puts("*************************************************");
}
