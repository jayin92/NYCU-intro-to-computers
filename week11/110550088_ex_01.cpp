#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* merge(int* ptr1, int size1, int* ptr2, int size2) {
    int idx1, idx2, sz;
    idx1 = idx2 = 0;
    sz = size1 + size2;
    int* res = (int*)calloc(50, sizeof(int));
    res[0] = sz;
    for (int i = 1; i <= sz; i++) {
        if (idx1 < size1 && idx2 < size2) {
            if (ptr1[idx1] < ptr2[idx2]) {
                res[i] = ptr1[idx1];
                idx1++;
            }
            else if (ptr1[idx1] > ptr2[idx2]) {
                res[i] = ptr2[idx2];
                idx2++;
            }
            else {
                res[i] = ptr1[idx1];
                idx1++;
                idx2++;
            }
        }
        else if (idx1 < size1) {
            res[i] = ptr1[idx1];
            idx1++;
        }
        else if(idx2 < size2){
            res[i] = ptr2[idx2];
            idx2++;
        }       
    }
    res[0] = sz;

    return res;
}

int main() {
    int mode;
    int a[40];
    int b[40];
    int sz1, sz2;
    while (true) {
        printf("enter 1 to compare or 0 to quit: ");
        scanf("%d", &mode);
        if (mode == 0) {
            break;
        }
        sz1 = sz2 = 0;
        printf("plz enter your array on the new line: ");
        do {
            scanf("%d", a + sz1);
            sz1++;
        } while (getchar() != '\n');
        printf("plz enter your array on the new line: ");
        do {
            scanf("%d", b + sz2);
            sz2++;
        } while (getchar() != '\n');


        int* merged = merge(a, sz1, b, sz2);
        int sz = merged[0];
        int ans[30];
        int szz = 0;
        int pre = -100000;
        for (int i = 1; i <= sz; i++) {
            if (merged[i] > pre) {
                ans[szz++] = merged[i];
                pre = merged[i];
            }
        }
        for (int i = 0; i < szz; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%4d ", ans[i]);
        }
        printf("\n");
        free(merged);
    }


    system("PAUSE");
    return 0;
}