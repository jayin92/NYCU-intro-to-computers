#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** matrix_multiplication(int **mat1, int row1, int col1, int **mat2, int row2, int col2);

int main() {
    char filename[128];
    while(true){
        printf("please enter input file: ");
        scanf("%s", filename);
        FILE* fptr;
        fptr = fopen(filename, "r");
        int r1, c1, r2, c2;
        r1 = c1 = r2 = c2 = 0;
        fscanf(fptr, "%d", &r1);
        getc(fptr);
        fscanf(fptr, "%d", &c1);
        int** mat1 = (int**)calloc(r1, sizeof(int*));
        for(int i=0;i<r1;i++){
            mat1[i] = (int*)calloc(c1, sizeof(int));
        }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                fscanf(fptr, "%d", &(mat1[i][j]));
            }
        }
        fscanf(fptr, "%d", &r2);
        getc(fptr);
        fscanf(fptr, "%d", &c2);
        int** mat2 = (int**)calloc(r2, sizeof(int*));
        for(int i=0;i<r2;i++){
            mat2[i] = (int*)calloc(c2, sizeof(int));
        }
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                fscanf(fptr, "%d", &(mat2[i][j]));
            }
        }
        int** res = matrix_multiplication(mat1, r1, c1, mat2, r2, c2);
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                printf("%8d", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        free(mat1);
        free(mat2);
    }
    system("pause");
    return 0;
}

int** matrix_multiplication(int **mat1, int row1, int col1, int **mat2, int row2, int col2){
    int** res = (int**)calloc(row1, sizeof(int*));
    for(int i=0;i<row1;i++){
        res[i] = (int*)calloc(col2, sizeof(int));
    }

    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col1;k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return res;
}