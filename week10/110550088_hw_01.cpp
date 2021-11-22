#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char a, char b, char c){
    if(n == 1){
        printf("Move disk 1 from %c to %c\n", a, c);
        return;
    }
    hanoi(n-1, a, c, b);
    printf("Move disk %d from %c to %c\n", n, a, c);
    hanoi(n-1, b, a, c);
}

int main(){
    while(true){
        int n;
        printf("Input the number of disks: ");
        scanf("%d", &n);
        if(n == 0){
            printf("No movement.\n\n");
            continue;
        }
        hanoi(n, 'A', 'B', 'C');
        printf("\n");
    }
    system("pause");
    return 0;
}

