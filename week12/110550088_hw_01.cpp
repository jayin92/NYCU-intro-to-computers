#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(char** a, char ** b){
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int m, n;
    printf("set the size of array A and B:");
    scanf("%d %d", &m, &n);
    char **a = (char**)calloc(m, sizeof(char*));
    char **b = (char**)calloc(n, sizeof(char*));
    while(printf("0: add a book, 1: delete a book, 2: exchange the books\n")){
        int mode;
        scanf("%d", &mode);
        if(mode == 0){
            int x, y, s;
            scanf("%d %d %s", &x, &y, &s);
            if(x == 0){
                if(y < m && a[y] == NULL){
                    a[y] = (char*)calloc(s+1, sizeof(char));
                    scanf("%s", a[y]);                    
                }
            } else if(x == 1) {
                if(y < n && b[y] == NULL){
                    b[y] = (char*)calloc(s+1, sizeof(char));
                    scanf("%s", b[y]);
                }
            }
        } else if(mode == 1){
            int x, y;
            scanf("%d %d", &x, &y);
            if(x == 0){
                if(y < m){
                    a[y] = NULL;
                }
            } else if(x == 1){
                if(y < n){
                    b[y] = NULL;
                }
            }

        } else if(mode == 2){
            int x, y;
            scanf("%d %d", &x, &y);
            if(x < m && y < n){
                swap(&(a[x]), &(b[y]));
            }
        }
        printf("A:\n");
        for(int i=0;i<m;i++){
            if(a[i] == NULL){
                printf("(null)\n");
            } else {
                printf("%s\n", a[i]);
            }
        }
        printf("B:\n");
        for(int i=0;i<n;i++){
            if(b[i] == NULL){
                printf("(null)\n");
            } else {
                printf("%s\n", b[i]);
            }
        }

    }

    system("pause");
    return 0;
}

