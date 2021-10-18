#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int pas[10][10];
    for(int i=0;i<10;i++){
        pas[i][0] = pas[i][i] = 1;
        for(int j=1;j<i;j++){
            pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
        }
    }
    printf("Input layers of pascal triangle (0 <= layers <= 9): ");
    scanf("%d", &n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            printf(" %d", pas[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

