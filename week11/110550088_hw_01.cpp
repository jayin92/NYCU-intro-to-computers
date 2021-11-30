#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* compare(const char* s, const char* t, int n){
    int* res = (int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        if(s[i] == t[i]){
            res[i] = 1;
        } else {
            res[i] = 0;
        }
    }   

    return res;
}

int main() {
    int n;
    printf("input n:");
    scanf("%d", &n);
    char *a = (char*)calloc(n+2, sizeof(char));
    char *b = (char*)calloc(n+2, sizeof(char));
    printf("input a:");
    scanf("%s", a);
    printf("input b:");
    scanf("%s", b);
    int* res = compare(a, b, n);
    for(int i=0;i<n;i++){
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}
