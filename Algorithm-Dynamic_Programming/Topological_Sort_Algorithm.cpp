#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>&visited, vector<int>&visitednodes, vector<vector<int>>graph){
    visited[node] = true;
    for(int x : graph[node]){
        if(!visited[x]) dfs(x, visited, visitednodes, graph);
    }
    visitednodes.push_back(node);
}

vector<int> topsort(int n, vector<vector<int>>graph){
    vector<bool>visited(n, false);
    vector<int>ordering;
    for(int i = 0; i<n; i++){
        if(!visited[i]) dfs(i, visited, ordering, graph);
    }
    return ordering;
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<vector<int>>graph(n);
        for(int i = 0; i<m; i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
        }
        vector<int>result = topsort(n, graph);
        for(int x : result){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
int dfs(i, node, visited, visitednodes, graph){
    visited[node] = true;
    for(auto x : graph[node]){
        if(!visited[x]){
            i = dfs(x, visited, visitednodes, graph);
        }
    }
    visitednode[i] = node;
    return i-1;
}

vector<int> topsort(){
    n = number of nodes;
    vector<bool> visited(n, false);
    vector<int> ordering(n, 0);
    i = n-1;
    for(int j = 0; j<n; j++){
        if(!visited[j]){
            dfs(j, visited, ordering, graph);
        }
    }
    return ordering;
}
*/