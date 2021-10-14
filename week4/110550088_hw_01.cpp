#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y){
    if(x < y) return x;
    else return y;
}

int main(){
    int a, b;
    printf("Please input the first integer: ");
    scanf("%d", &a);
    printf("Please input the second integer: ");
    scanf("%d", &b);
    int i = min(a, b);
    printf("The greatest divisor: ");
    while(i != 0){
        if(a % i == 0 && b % i == 0){
            printf("%d\n", i);
            break;
        }
        i --;
    }
    system("pause");
    return 0;
}

