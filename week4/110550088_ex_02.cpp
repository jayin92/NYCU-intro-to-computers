#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Please input a positive integer: ");
    scanf("%d", &n);
    printf("Factors of %d: ", n);
    for(int i=1;i<=n;i++){
        if(n % i == 0){
            printf("%d ", i);
        }
    }
    printf("\n");  

    system("pause");
    return 0;
}
