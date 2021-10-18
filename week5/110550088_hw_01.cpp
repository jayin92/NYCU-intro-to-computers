#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(){
    int a[15][15], b[15][15], ans[15][15];
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &(a[i][j]));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            scanf("%d", &(b[i][j]));
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            ans[i][j] = 0;
            for(int k=0;k<n;k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}

