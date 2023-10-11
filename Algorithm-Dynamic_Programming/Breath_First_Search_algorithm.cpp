#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(){

}

/*
//breath first search
n = number of nodes in the graph
g = adjancy list representing unweighted graph


vector<int> solve(start_node){
    queue<int> q;
    q.push(start_node);
    vector<int>visited(n, false);
    visited[start_node] = true;
    vector<int> preve(n);
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                prev[x] = node;
            }
        }

    }
    return prev;
}

vector<int> reconstructPath(start_node, end_node, prev){
    vector<int>path;
    int i = end_node;
    while(i){
        path.push_back(i);
        i = prev[i];
    }
    if(path[0] == start_node) return path;
    return {};
}

vector<int> bfs(strat_node, end_node){
    prev = solve(s);
    return reconstructPath(start_node, end_node, prev);
}
*/