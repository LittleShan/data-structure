#include "triple.h"

/**
 * create a sparse matrix
 */
TSMatrix create_triple(int matrix[][COLS], int rows, int cols)
{
	int i, j;
	
	TSMatrix M;

	M.rows = rows;
	M.cols = cols;
	M.terms = 0;

	for (i = 1; i <= M.rows; i++) {
		for (j = 1; j <= M.cols; j++) {
			if (matrix[i - 1][j - 1] != 0) {
				M.data[M.terms].i = i;
				M.data[M.terms].j = j;
				M.data[M.terms].data = matrix[i - 1][j - 1];
				M.terms++;
			}
		}
	}

	return M;
}

/**
 * The common algorithm realizes matrix transponse
 */
TSMatrix transponse_matrix(TSMatrix M)
{
	TSMatrix T;

	int q = 0;
	int p;
	int col;

	T.cols = M.rows;
	T.rows = M.cols;
	T.terms = M.terms;
	
	if (T.terms) {
		for (col = 1; col <= M.cols; col++) {
			for (p = 0; p < M.terms; p++) {
				if (M.data[p].j == col) {
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].data = M.data[p].data;
					q++;
				}
			}
		}
	}

	return T;
}

/**
 * The fast transponse algorithm implements matrix transponse 
 */
TSMatrix fast_transponse_matrix(TSMatrix M)
{
	TSMatrix T;
	
	int array[NUMS];
	int cpot[NUMS];

	int col, i, t, j, p, q;

	T.cols = M.rows;
	T.rows = M.cols;
	T.terms = M.terms;

	if (T.terms) {
		for (col = 1; col <= M.cols; col++) {
			array[col] = 0;
		}

		/* The number of non-zero element at M each column */
		for (t = 0; t < M.terms; t++) {
			j = M.data[t].j;
			array[j]++;
		}

		cpot[1] = 1;
		/* The position of col column first non-zero element at new triple */
		for (col = 2; col <= M.cols; col++) {
			cpot[col] = cpot[col - 1] + array[col - 1];
		}

		for (p = 0; p < M.terms; p++) {
			col = M.data[p].j;
			q = cpot[col];

			T.data[q - 1].i = M.data[p].j;
			T.data[q - 1].j = M.data[p].i;
			T.data[q - 1].data = M.data[p].data;

			cpot[col]++;
		}
	}

	return T;
}
