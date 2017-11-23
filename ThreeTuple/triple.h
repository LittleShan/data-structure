#ifndef _TRIPLE_H
#define _TRIPLE_H

#define NUMS 50

#define ROWS 5
#define COLS 4

/* Triple data struct */
typedef struct
{
	int i;		/* The row location */
	int j;		/* The column location */
	int data;	/* The value of element */
}Triple;

/* Matrix struct */
typedef struct
{
	Triple data[NUMS];	/* Triple */
	int rows;		/* The rows of Matrix */
	int cols;		/* The columns of Matrix */
	int terms;		/* The number of non-zero elements */
}TSMatrix;

/* create a sparse matrix */
TSMatrix create_triple(int matrix[][COLS], int rows, int cols);

/* The common algorithm realizes matrix transponse  */
TSMatrix transponse_matrix(TSMatrix M);

/* The fast transponse algorithm implements matrix transponse  */
TSMatrix fast_transponse_matrix(TSMatrix M);

#endif
