#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void transfer(){
    FILE* fptr = fopen("input.txt", "r");
    char c;
    while((c = getc(fptr)) != EOF){
        if('a' <= c && c <= 'z'){
            printf("%c", c - 'a' + 'A');
        } else if('A' <= c && c <= 'Z'){
            printf("%c", c - 'A' + 'a');
        } else {
            printf("%c", c);
        }
    }
}

int main(){
    transfer();
}
