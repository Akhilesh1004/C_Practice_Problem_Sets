#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int dp[1000];
int find(int n){
    for(int d = n-1; d >= 0; d--){
        for(int a = 0; a < n; a++){
            if(d==a) continue;
            int b = 0, c = n-1;
            while(b==a || b==d) b++;
            while(c==a || c==d) c--;
            while(b < c){
                int diff = dp[d] - (dp[a]+dp[b]+dp[c]);
                if(diff==0) return d;
                if(diff > 0){
                    b++;
                    while(b==a || b==d) b++;
                }else{
                    c--;
                    while(c==a || c==d) c--;
                }
            }
        }
    }
    return -1;
}
int main(){
    int n;
    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++){
            scanf("%d", &dp[i]);
        }
        sort(dp, dp+n);
        int d = find(n);
        if(d != -1) printf("%d\n", dp[d]);
        else printf("no solution\n");
    }
    return 0;
}