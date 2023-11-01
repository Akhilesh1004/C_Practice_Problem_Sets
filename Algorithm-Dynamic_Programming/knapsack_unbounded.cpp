#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int knapsackunbounded(int n, vector<int>value, vector<int>weight){
    if(value.empty() || weight.empty() || value.size() != weight.size()) return -1;
    vector<int>dp(n+1, 0);
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<value.size(); j++){
            if((i-weight[j]) >= 0) dp[i] = max(dp[i], dp[i-weight[j]]+value[j]);
        }
    }
    return dp[n];
}

vector<int> knapsackunbounded_selected(int n, vector<int>value, vector<int>weight){
    if(value.empty() || weight.empty() || value.size() != weight.size()) return {};
    vector<vector<int>>dp(value.size()+1, vector<int>(n+1));
    for(int i = 1; i<=value.size(); i++){
        for(int j = 1; j<=n; j++){
            if(j>=weight[i-1]) dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i-1]]+value[i-1]);
        }
    }
    vector<int>itemselected;
    int capacity = n;
    int i = value.size();
    while(i>0 && capacity>0){
        if(dp[i][capacity] != dp[i-1][capacity]){
            itemselected.push_back(i-1);
            capacity -= weight[i-1];
        }else{
            i--;
        }
    }
    return itemselected;
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>value(m);
        vector<int>weight(m);
        for(int i = 0; i<m; i++){
            cin>>weight[i]>>value[i];
        }
        cout<<knapsackunbounded(n, value, weight)<<endl;
        vector<int>result = knapsackunbounded_selected(n, value, weight);
        for(int x : result){
            cout<<weight[x]<<' '<<value[x]<<endl;
        }
    }
    return 0;
}