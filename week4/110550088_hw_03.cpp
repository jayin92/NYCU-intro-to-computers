#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int key = rand() % 100 + 1;
    printf("Key: %d\n", key);
    int cnt = 1;
    int min = 1;
    int max = 100;
    int guess = 0;
    while(1){
        printf("(%d guess) %d ~ %d: ", cnt++, min, max);
        scanf("%d", &guess);
        if(guess == key){
            printf("Bingo!\n");
            break;
        }
        if(guess < min || guess > max){
            printf("Out of range.\n");
            continue;
        }
        if(key > guess){
            min = guess;
        } else {
            max = guess;
        }
    }
    printf("Key: %d\n", key);

    system("pause");
    return 0;
}

