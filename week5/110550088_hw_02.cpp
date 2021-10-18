#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int len = 1000;

int main() {
    char s[len];
    int c[26][len];
    int nc[26][len];
    int sz_c[26] = {0};
    int sz_nc[26] = {0};
    scanf("%s", s);
    int sz = strlen(s);
    int idx;
    for(int i=0;i<sz;i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            idx = s[i] - 'A';
            c[idx][sz_c[idx]++] = i;
        } else if('a' <= s[i] && s[i] <= 'z') {
            idx = s[i] - 'a';
            nc[idx][sz_nc[idx]++] = i;
        }
    }
    for(int i=0;i<26;i++){
        if(sz_c[i] == 0) continue;
        printf("%c: ", 'A' + i);
        for(int j=0;j<sz_c[i];j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<26;i++){
        if(sz_nc[i] == 0) continue;
        printf("%c: ", 'a' + i);
        for(int j=0;j<sz_nc[i];j++){
            printf("%d ", nc[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

