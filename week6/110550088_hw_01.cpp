#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char sen[1000][1000];
    scanf("%d", &n);
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            sen[i][j] = '\0';
        }
    }

    for(int i=0;i<n;i++){
        scanf("%s", sen[i]);
    }

    FILE* fptr1 = fopen("input.txt", "r");
    FILE* fptr2 = fopen("output.txt", "w");
    char c;
    char tmp[1000];
    while((c = getc(fptr1)) != EOF){
        // printf("%c", c);
        if(!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))){
            bool flag = true;
            for(int i=0;i<n;i++){
                // printf("%s %s\n", sen[i], tmp);
                // printf("%d %d\n", (int)strlen(sen[i]), (int)strlen(tmp));
                if(strcmp(tmp, sen[i]) == 0){
                    fprintf(fptr2, "***");
                    flag = false;
                    break;
                }
            }
            if(flag){
                fprintf(fptr2, "%s", tmp);
            }
            fprintf(fptr2, "%c", c);

            // memset(tmp, '\0', 1000);
            for(int i=0;i<1000;i++){
                tmp[i] = '\0';
            }
        } else {
            char cc[2];
            cc[0] = c;
            cc[1] = '\0';
            strcat(tmp, cc);
        }
    }
    
    return 0;
}
