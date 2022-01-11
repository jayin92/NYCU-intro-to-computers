// #include <stdio.h>

// int cal(int n){
//     int res = 0;
//     while(n != 0){
//         int tmp = n % 10;
//         res += tmp * tmp;
//         n /= 10;
//     }

//     return res;
// }

// int main(){
//     long long cycle[1000];
//     int n;
//     scanf("%d", &n);
//     cycle[0] = n;
//     for(int i=1;;i++){
//         n = cal(n);
//         cycle[i] = n;
//         if(n == 1){
//             printf("1\n");
//             return 0;
//         }
//         for(int j=0;j<i;j++){
//             if(cycle[j] == cycle[i]){
//                 printf("0\n");
//                 return 0;
//             }
//         }
//     }
// }

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(void){
    long long int n;
    long long int s[10000];
    scanf("%lld",&n);
    int tmp=0,temp=0;
    for(int i=0;;i++){
        temp = 0;
        while(n>0){
            tmp=n%10;
            temp+=tmp*tmp;
            n=n/10;
        }
        s[i]=temp;
        n = temp;
        if(s[i]==1){
            printf("1\n");
            return 0;
        }
        else{
            for (int j=0;j<i;j++){
                if (temp==s[j]){
                    printf("0\n");
                    return 0;
                }
            }
        }
    }
}