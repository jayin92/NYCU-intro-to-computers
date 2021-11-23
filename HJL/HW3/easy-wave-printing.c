#include <stdio.h>
#include <stdlib.h>


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, f;
        scanf("%d %d", &a, &f);
        for(int i=0;i<f;i++){
            for(int j=1;j<=a;j++){
                for(int k=0;k<j;k++){
                    printf("%d", j);
                }
                printf("\n");
            }
            for(int j=a-1;j>=1;j--){
                for(int k=0;k<j;k++){
                    printf("%d", j);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}