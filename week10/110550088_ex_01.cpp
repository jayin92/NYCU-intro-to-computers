#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum(int a[20], int pos){
    if(pos == 0){
        return a[0];
    } else {
        return a[pos] + sum(a, pos-1);
    }
}

int main(){
    int pos;
    int a[20];
    int sz = 0;
    printf("Please input an array (size less than 10): ");
    do{
        scanf("%d", a+sz);
        sz ++;
    } while(getchar() != '\n');
    
    printf("How many elements to sum from head: ");
    scanf("%d", &pos);
    if(pos > sz){
        printf("Out of range.\n");
    } else {
        if(pos == 0){
            printf("The summation is 0.\n");
        } else {
            printf("The summation is %d.\n", sum(a, pos-1));
        }
    }
    system("pause");
    return 0;
}

