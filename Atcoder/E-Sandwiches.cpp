#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main(){
    long long n, sum, t;
    while(scanf("%lld", &n) != EOF){
        sum = 0;
        vector<long long> dp(n+5, 0);
        vector<long long> t(n+5, 0);
        vector<long long> count(n+5, 0);
        for(long long i = 1; i<=n; i++){
            cin >> dp[i];
            if(count[dp[i]] != 0){
                //sum += t[dp[i]]*count[dp[i]]*(n-t[dp[i]]-count[dp[i]]);
                sum += i*count[dp[i]] - t[dp[i]] - (count[dp[i]] - 1) * count[dp[i]] / 2 - count[dp[i]];
            }
            count[dp[i]]++;
            t[dp[i]] += i;
        }
        /*
        for(int i = 0; i<n-3; i++){
            for(int k = n-1; k>i; k--){
                if(dp[i] == dp[k]){
                    for(int j= i+1; j<k; j++){
                        if(dp[i] != dp[j]){
                            sum++;
                        }
                    }
                }
            }
        }*/
        printf("%lld\n", sum);
    }
    return 0;
}