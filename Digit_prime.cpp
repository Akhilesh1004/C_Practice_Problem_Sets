#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isprime(int n){
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2 == 0) return false;
    for(int d = 3; d*d <= n; d+=2){
        if(n%d == 0) return false;
    }
    return true;
}

int main(){
    int test, a, b, dp[1000000] = {0};
    for(int i =2; i<1000000; i++){
        if(isprime(i)){
            int all = 0, k = i;
            while(k > 0){
                all += k%10;
                k /= 10;
            }
            if(isprime(all)) dp[i] = dp[i-1]+1;
            else dp[i] = dp[i-1];
        }else dp[i] = dp[i-1];
    }
    scanf("%d", &test);
    if(test<=0 || test>500000) return 0;
    while(test--){
        scanf("%d%d", &a, &b);
        if(a <=0 || b <= 0 || a >=  1000000 || b >=  1000000) return 0;
        printf("%d\n", dp[b]-dp[a-1]);
    }
    return 0;
}

