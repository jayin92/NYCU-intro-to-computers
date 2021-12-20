// to construct the matrix by given row and column
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"


matrix2D* matrix2D_construct(int m, int n) {
	matrix2D* res = new matrix2D;

	res->row = m;
	res->column = n;
	res->mat = (vector*)calloc(m, sizeof(vector));

	for (int i = 0; i < m; i++) {
		res->mat[i] = *(vector_construct(n));
	}

	return res;
}

// fill the matrix with specific number
void matrix2D_fillwith(matrix2D* A, int num) {
	int m = A->row;
	int n = A->column;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A->mat[i].vec[j] = num;
		}
	}
}

// check 2 matrix with the right shape, if they can multiple together, return the result, or print shape error
matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B) {
	int a_row = A->row;
	int a_col = A->column;
	int b_row = B->row;
	int b_col = B->column;
	if (a_col != b_row) {
		printf("shape error\n");
		return NULL;
	}

	matrix2D* res = matrix2D_construct(a_row, b_col);
	matrix2D_fillwith(res, 0);

	for (int i = 0; i < a_row; i++) {
		for (int j = 0; j < b_col; j++) {
			for (int k = 0; k < a_col; k++) {
				res->mat[i].vec[j] += A->mat[i].vec[k] * B->mat[k].vec[j];
			}
		}
	}

	return res;
}