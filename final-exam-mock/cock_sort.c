#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a[] = {1, 2, 56, 3, 2, 4, 7, 8, 9, 10, 12, 4, 6, 5};
    int n = sizeof(a) / sizeof(int);
    int tmp;
    for(int i=1;i<n-1;i++){
        for(int j=i-1;j<n-i;j++){
            if(a[j] > a[j+1]){
                swap(a+j, a+j+1);
            }
        }
        for(int j=n-i-1;j>=i;j--){
            if(a[j] < a[j-1]){
                swap(a+j, a+j-1);
            }
        }
    }

    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");

}