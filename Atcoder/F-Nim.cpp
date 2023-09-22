#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MOD = 998244353;
int dp[80][12][12][12][2][2][2][2][2][2];
int p[80];
int a1, a2, a3;

long long int dfs(int u, int r1, int r2 ,int r3, bool l1, bool l2, bool l3, bool z1, bool z2, bool z3){
    if(u==0) return !z1 && !z2 && !z3 && !r1 && !r2 && !r3;
    if(dp[u][r1][r2][r3][l1][l2][l3][z1][z2][z3] != -1) return dp[u][r1][r2][r3][l1][l2][l3][z1][z2][z3];
    int up1 = l1?p[u]:1, up2 = l2?p[u]:1, up3 = l3?p[u]:1;
    long long int ans = 0;
    for(long long int i = 0; i<=up1; i++){
        for(long long int j = 0; j<=up2; j++){
            for(long long int k = 0; k<=up3; k++){
                if(i ^ j ^ k != 0) continue;
                long long int newr1 = (r1 + (i<<(u-1)))%a1;
                long long int newr2 = (r2 + (j<<(u-1)))%a2;
                long long int newr3 = (r3 + (k<<(u-1)))%a3;
                ans = (ans + dfs(u-1, newr1, newr2, newr3, l1&&i==p[u], l2&&j==p[u], l3&&k==p[u], z1&&i==0, z2&&j==0, z3&&k==0))%MOD;
            }
        }
    }
    return dp[u][r1][r2][r3][l1][l2][l3][z1][z2][z3] = ans;
}

int main(){
    long long int n;
    while(scanf("%lld %d %d %d", &n, &a1 ,&a2, &a3) != EOF){
        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        while(n){
            p[++cnt] = n%2;
            n /= 2;
        }
        printf("%lld\n", dfs(cnt, 0, 0, 0, 1, 1, 1, 1, 1, 1));
    }
    return 0;
}