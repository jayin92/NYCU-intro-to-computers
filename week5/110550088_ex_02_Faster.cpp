#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double START = clock();
    int n = 80000;
    int ans[80005];
    int sz = 0;
    for(int i=2;i<=n;i++) {
        bool flag = true;
        for(int j=2;j*j<=i;j++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans[sz++] = i;
        }
    }
    double END = clock();
    for(int i=0;i<sz;i++) {
        printf("%d\n", ans[i]);
    }
    printf("Time: %lf\n", (END - START) / CLOCKS_PER_SEC);
    system("pause");
    return 0;
}
