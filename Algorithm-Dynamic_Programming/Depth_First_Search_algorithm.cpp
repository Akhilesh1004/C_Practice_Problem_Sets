#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long int sum;
int n, m;


void dfs(int node, long long int len, vector<bool>&visited, vector<vector<int>>&dp){
    visited[node] = true;
    sum = max(sum, len);
    for(int i = 1; i<=n; i++){
        if(dp[node][i] && !visited[i]) dfs(i, len+dp[node][i], visited, dp);
    }
    visited[node] = false;
}

int main(){
    int a, b, c;
    while(cin>>n>>m){
        sum = 0;
        vector<bool>visited(n, false);
        vector<vector<int>>dp(n+5, vector<int>(n+5));
        for(int i = 0; i<m; i++){
            cin>>a>>b>>c;
            dp[a][b] = c;
            dp[b][a] = c;
        }
        for(int i = 1; i<=n; i++) dfs(i, 0, visited, dp);
        cout<<sum<<endl;
    }
    return 0;
}


//connected components
/*
n = number of nodes int the graph
g = adjacency list representing graph
count = 0
vector<int>component(n);
vector<bool>visited(n, false);

void findcomponent(){
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
}

void dfs(node){
    visited[node] = true;
    component[node] = count;
    for(auto x : g[node]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

//depth first search

n = number of nodes int the graph
g = adjacency list representing graph
vector<bool>visited(n, false);

void dfs(node){
    visited[node] = true;
    for(auto x : g[node]){
        if(!visited[x]) dfs(x);
    }
}
*/