#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long sum;
int n, m;

void dfs(int x, long long len, vector<bool> &visited, vector<vector<int>> &dp){
    visited[x] = true;
    sum = max(sum, len);
    for(int i = 1; i<=n; i++){
        if(dp[x][i] && !visited[i]) dfs(i, len+dp[x][i], visited, dp);
    }
    visited[x] = false;
}

 int main(){
    while(scanf("%d %d", &n ,&m) != EOF){
        sum = 0;
        int a, b, c;
        vector<vector<int>> dp(n+5, vector<int>(n+5, 0));
        vector<bool> visited(15, false);
        for(int i = 0; i<m; i++){
            cin>>a>>b>>c;
            dp[a][b] = c;
            dp[b][a] = c;
        }
        for(int i = 1; i<=n; i++) dfs(i, 0, visited, dp);
        printf("%lld\n", sum);
    }
    return 0;
 }