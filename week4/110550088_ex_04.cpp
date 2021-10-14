#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int pw;
    printf("Please input a five digits number as password: ");
    scanf("%d", &pw);
    int remain = 4;
    int in;
    while(remain-- != 1){
        printf("Please input the password (remaining tries: %d): ", remain);
        scanf("%d", &in);
        if(in == pw){
            break;
        }
    }
    if(in != pw){
        printf("You have entered the wrong password for three times!\n");
    } else {
        printf("Password is correct, welcome back.\n");
    }
    system("pause");
    return 0;
}

