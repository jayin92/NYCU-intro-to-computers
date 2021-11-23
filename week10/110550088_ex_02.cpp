#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[20], int l, int r, int tar) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (a[mid] > tar) {
        return binary_search(a, l, mid - 1, tar);
    }
    else if (a[mid] < tar) {
        return binary_search(a, mid + 1, r, tar);
    }
    else {
        return mid;
    }
}

int main() {
    while (true) {
        int a[20];
        int sz = 0;
        printf("Please input a sorted array(size less than 10): ");
        do {
            scanf("%d", a + sz);
            sz++;
        } while (getchar() != '\n');
        int tar;
        printf("Please input the number you want to find: ");
        scanf("%d", &tar);
        int ans = binary_search(a, 0, sz, tar);
        if (ans == -1) {
            printf("Could not find the number.\n");
        }
        else {
            printf("The number is at the index %d.\n", ans);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

