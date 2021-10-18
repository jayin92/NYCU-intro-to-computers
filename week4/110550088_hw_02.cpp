#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

bool check(int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            res += i;
        }
    }
    return res == n;
}

int main() {
    int n;
    printf("Please input an integer: ");
    scanf("%d", &n);
    printf("All perfect numebers which is less than this integer:\n");
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    system("pause");
    return 0;
}

