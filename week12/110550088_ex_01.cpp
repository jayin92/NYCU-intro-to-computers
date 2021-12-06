#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
    int **a = (int**)calloc(3, sizeof(int*));
    a[0] = (int*)calloc(5, sizeof(int));
    a[1] = (int*)calloc(4, sizeof(int));
    a[2] = (int*)calloc(7, sizeof(int));
    int sz[4] = {5, 4, 7, 0};
    printf("step 1:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<sz[i];j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    a[1] = (int*)realloc(a[1], sizeof(int) * 9);
    sz[1] = 9;
    for(int i=4;i<sz[1];i++){
        a[1][i] = 1;
    }
    printf("step 2:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<sz[i];j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    a = (int**)realloc(a, sizeof(int*) * 4);
    a[3] = (int*)calloc(2, sizeof(int));
    sz[3] = 2;
    for(int i=0;i<sz[3];i++){
        a[3][i] = 2;
    }
    printf("step 3:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<sz[i];j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    free(a[1]);
    a[1] = a[2];
    a[2] = a[3];
    sz[1] = sz[2];
    sz[2] = sz[3];
    a = (int**)realloc(a, sizeof(int*) * 3);
    printf("step 4:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<sz[i];j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}

