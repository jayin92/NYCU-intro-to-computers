#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[1000];
    scanf("%s", s);
    int cnt;
    int sz = strlen(s);
    for(int i=0;i<sz;i++){
        if(s[i] == '(') cnt ++;
        else if(s[i] == ')') cnt --;
        if(cnt < 0){
            break;
        }
    }
    if(cnt != 0){
        printf("error\n");
    } else {
        printf("correct\n");
    }
}
