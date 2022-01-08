#include <stdio.h>

int cal(int n){
    int res = 0;
    while(n != 0){
        int tmp = n % 10;
        res += tmp * tmp;
        n /= 10;
    }

    return res;
}

int main(){
    long long cycle[10000];
    long long n;
    scanf("%d", &n);
    cycle[0] = n;
    for(int i=1;;i++){
        n = cal(n);
        cycle[i] = n;
        if(n == 1){
            printf("1\n");
            return 0;
        }
        for(int j=0;j<i;j++){
            if(cycle[j] == cycle[i]){
                printf("0\n");
                return 0;
            }
        }
    }
}