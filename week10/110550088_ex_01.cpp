#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum(int a[20], int pos, int res) {
    if (pos == 0) {
        return res+a[pos];
    }
    else {
        return sum(a, pos - 1, res+a[pos]);
    }
}

int main() {
    while (true) {
        int pos;
        int a[20];
        int sz = 0;
        printf("Please input an array(size less than 10): ");
        do {
            scanf("%d", a + sz);
            sz++;
        } while (getchar() != '\n');

        printf("How many elements to sum from head: ");
        scanf("%d", &pos);
        if (pos > sz) {
            printf("Out of range.\n");
        }
        else {
            if (pos == 0) {
                printf("The summation is 0.\n");
            }
            else {
                printf("The summation is %d.\n", sum(a, pos - 1, 0));
            }
        }
        printf("\n");
    }

    system("pause");
    return 0;
}

