#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display_menu();

int main(int argc, char *argv[])
{
	char menu_id;

	Stack *s = init_stack();

	while (1) {
		display_menu();

		menu_id = getchar();
		
		switch (menu_id) {
			case '1':
				push(s);
				break;
			case '2':
				pop(s);
				break;
			case '3':
				decimal_to_binary();
				break;
			case '0':
				puts("Exit");
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

	puts("**************Stack**************");
	puts("*                               *");
	puts("*          1)Push stack         *");
	puts("*          2)Pop stack          *");
	puts("*          3)Decimal to binary  *");
	puts("*          0)Exit               *");
	puts("*                               *");
	puts("*********************************");
}
