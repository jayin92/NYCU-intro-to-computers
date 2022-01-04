#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

void merge_sort(int a[], int l, int r){
    // printf("(l, r) = (%d, %d)\n", l, r);
    if(l+1 == r) return;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid, r);
    int idx1 = l;
    int idx2 = mid;
    int b[MAXN];
    for(int i=0;i<r-l;i++){
        if(idx1 == mid){
            b[i] = a[idx2];
            idx2++;
        } else if(idx2 == r){
            b[i] = a[idx1];
            idx1 ++;
        } else if(a[idx1] > a[idx2]){
            b[i] = a[idx2];
            idx2++;
        } else {
            b[i] = a[idx1];
            idx1++;
        }
    }

    for(int i=0;i<r-l;i++)
        a[i+l] = b[i];

}


int main(){
    int a[MAXN];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", a+i);
    }

    merge_sort(a, 0, n);
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");


    

}
