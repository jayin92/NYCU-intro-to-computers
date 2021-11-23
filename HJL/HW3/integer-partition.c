#include <stdio.h>
#include <stdlib.h>

void solve(int a[1005], int sz, int n, int pre){    
    for(int i=pre;i<=n-i;i++){        
        int b[1005];
        for(int j=0;j<sz;j++) b[j] = a[j];
        b[sz] = i;
        solve(b, sz+1, n-i, i);
    }
    if(sz != 0){
        for(int i=0;i<sz;i++){
            printf("%d+", a[i]);
        }   
        printf("%d\n", n);
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[1005];
    solve(a, 0, n, 1);
    printf("%d\n", n);
}