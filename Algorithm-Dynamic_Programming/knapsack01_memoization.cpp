#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int knapsack01(int n, int m, vector<int>value, vector<int>weight){
    if(n<0 || value.empty() || weight.empty() || value.size() != weight.size()) return -1;
    if(n == 0 || m == 0) return 0;
    if(weight[m-1]>n) return knapsack01(n, m-1, value ,weight);
    else return max(value[m-1]+knapsack01(n-weight[m-1], m-1, value, weight), knapsack01(n, m-1, value, weight));

}

vector<int> knapsack01_selected(int n, int m, vector<int>value, vector<int>weight){
    if(n<0 || value.empty() || weight.empty() || value.size() != weight.size()) return {};
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(j>=weight[i-1]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]]+value[i-1]);
        }
    }
    vector<int>itemselected;
    int capacity = n;
    for(int i = m; i>0; i--){
        if(dp[i][capacity] != dp[i-1][capacity]){
            itemselected.push_back(i-1);
            capacity -= weight[i-1];
        }
    }
    return itemselected;
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>value(m), weight(m);
        for(int i = 0; i<m; i++){
            cin>>weight[i]>>value[i];
        }
        cout<<knapsack01(n, m, value, weight)<<endl;
        vector<int>result = knapsack01_selected(n, m, value, weight);
        for(int x : result){
            cout<<weight[x]<<" "<<value[x]<<endl;
        }
    }
    return 0;
}