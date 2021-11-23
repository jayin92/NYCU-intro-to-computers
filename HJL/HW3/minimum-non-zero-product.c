#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    const long long MOD = 1e9+7;
    scanf("%d", &n);
    long long ans = 1;
    long long tmp = (long long)1 << n;
    long long x = (1LL << (n-1))-1;
    long long y = tmp - 2LL;
    long long res = 1;
    // printf("%d\n", x);
    // printf("%d\n", y);
    while(x){
        if (x & 1) res = (res * y) % MOD;
        x = x >> 1;
        y = (y * y) % MOD;
    }
    // printf("%d\n", res);
    ans *= res;
    ans %= MOD;
    ans *= tmp - 1LL;
    ans %= MOD;
    printf("%lld\n", ans);
}