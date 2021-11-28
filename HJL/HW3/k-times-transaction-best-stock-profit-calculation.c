#include <stdio.h>
#include <stdlib.h>

int ans;
int a[1005];

void afterbuy(int idx, int n, int k, int pre, int cur);
void beforebuy(int idx, int n, int k, int cur);

void afterbuy(int idx, int n, int k, int pre, int cur){
    // printf("%d %d %d %d %d\n", idx, n, k, pre, cur);
    if(idx == n || k == 0){
        if(cur > ans) ans = cur;
        return;
    }
    if(k == 0){
        return;
    }
    afterbuy(idx+1, n, k, pre, cur);
    beforebuy(idx+1, n, k-1, cur+a[idx]-pre);
}

void beforebuy(int idx, int n, int k, int cur){
    if(idx == n || k == 0){
        if(cur > ans) ans = cur;
        return;
    }
    beforebuy(idx+1, n, k, cur);
    afterbuy(idx+1, n, k, a[idx], cur);
}

int main(){
    int n, k;
    ans = 0;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", a+i);
    }
    beforebuy(0, n, k, 0);
    printf("%d\n", ans);

}