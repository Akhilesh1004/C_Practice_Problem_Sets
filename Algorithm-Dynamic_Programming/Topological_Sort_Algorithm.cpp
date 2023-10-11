#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){

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