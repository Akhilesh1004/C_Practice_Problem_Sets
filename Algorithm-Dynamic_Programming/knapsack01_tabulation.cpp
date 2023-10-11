#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int knapsack01(int n, vector<int>value, vector<int>weight){
    if(n<0 || value.empty() || weight.empty() || value.size() != weight.size()) return -1;
    vector<vector<int>>dp(value.size()+1, vector<int>(n+1, 0));
    for(int i = 1; i<=value.size(); i++){
        int w = weight[i-1], v = value[i-1];
        for(int j = 1; j<=n; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=w && dp[i-1][j-w]+v > dp[i][j]) dp[i][j] = dp[i-1][j-w]+v;
        }
    }
    return dp[value.size()][n];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>weight(m), value(m);
        for(int i = 0; i<m; i++){
            cin>>weight[i]>>value[i];
        }
        cout<<knapsack01(n, value, weight)<<endl;
    }
    return 0;
}