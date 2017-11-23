#include <stdio.h>
#include "triple.h"

int main(int argc, char *argv[])
{
	int i, j;

	TSMatrix M, T;

	/* Maxtri */
	int matrix[ROWS][COLS] = {
		{0, 0, 0, 1},
		{0, 2, 0, 0},
		{5, 0, 0, 3},
		{0, 0, 4, 0},
		{0, 8, 0, 0},
	};

	
	puts("====Matrix====");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/* Maxtri trun to triple */
	M = create_triple(matrix, ROWS, COLS);
	
	puts("====Triple====");
	printf("i  j  data\n");
	puts("------------");
	for (i = 0; i < M.terms; i++) {
		printf("%d  %d  %d\n", M.data[i].i, M.data[i].j, M.data[i].data);
	}
	printf("\n");

	/* The common algorithm realizes matrix transponse */
	puts("====Ordinary algorithm====");
	printf("i  j  data\n");
	puts("------------");
	T = transponse_matrix(M);
	for (i = 0; i < T.terms; i++) {
		printf("%d  %d  %d\n", T.data[i].i, T.data[i].j, T.data[i].data);
	}
	printf("\n");

	/* The fast transponse algorithm implements matrix transponse */
	puts("====The fast transponse algorithm====");
	printf("i  j  data\n");
	puts("------------");
	T = fast_transponse_matrix(M);
	for (i = 0; i < T.terms; i++) {
		printf("%d  %d  %d\n", T.data[i].i, T.data[i].j, T.data[i].data);
	}

	return 0;
}
