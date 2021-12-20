#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"

int main() {
    int a_row, a_col, b_row, b_col, a, b;
    scanf("%d %d %d %d %d %d", &a_row, &a_col, &b_row, &b_col, &a, &b);
    
    matrix2D* A = matrix2D_construct(a_row, a_col);
    matrix2D* B = matrix2D_construct(b_row, b_col);

    matrix2D_fillwith(A, a);
    matrix2D_fillwith(B, b);

    matrix2D* res = matrix2D_multiple(A, B);
    if (res != NULL) {
        int m = res->row;
        int n = res->column;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", res->mat[i].vec[j]);
            }
            printf("\n");
        }
    }

    system("pause");
    return 0;
}

