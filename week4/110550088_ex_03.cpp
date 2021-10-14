#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n;
    printf("Please input a positive integer: ");
    scanf("%lld", &n);
    printf("%lld\n", n);
    int cnt = 0;
    while (n != 0 && n != 1) {
        if (n % (long long)2 == 0) {
            n /= (long long)2;
        }
        else {
            n = (long long)3 * n + (long long)1;
        }
        printf("%lld ", n);
        cnt++;
        if (cnt == 10) {
            printf("\n");
            cnt = 0;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}

