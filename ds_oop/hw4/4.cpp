#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<int, int>memo;

bool is_cycle(vector<vector<int>>dp, vector<bool>&visited, int node, int parent){
    visited[memo[node]] = true;
    for(int i = 0; i<dp[memo[node]].size(); i++){
        if(!visited[memo[dp[memo[node]][i]]]){
            if(is_cycle(dp, visited, dp[memo[node]][i], node)) return true;
        }else if(dp[memo[node]][i] != parent) return true;
    }
    return false;
}

bool solve(vector<vector<int>>dp, vector<int>nodes){
    vector<bool>visited(105, false);
    if(is_cycle(dp, visited, nodes[0], -1)){
        //cout<<"cycle\n";
        return false;
    }
    for(int i = 0; i<nodes.size(); i++){
        if(!visited[memo[nodes[i]]]){
            //cout<<"not connect\n";
            return false;
        }
    }
    return true;
}

int main(){
    int x, y;
    vector<vector<int>>dp, dp2(105);
    vector<int>nodes;
    int index = 0;
    while(cin>>x>>y && (x+y)!=0){
        dp.push_back({x, y});
        //dp[y].push_back(x);
        nodes.push_back(y);
        nodes.push_back(x);
        index++;
    }
    if(dp.size() == 0){
        cout<<"True\n";
        return 0;
    }
    set<int>s(nodes.begin(), nodes.end());
    vector<int>result(s.begin(), s.end());
    for(int i = 0; i<result.size(); i++){
        memo[result[i]] = i;
        for(int j = 0; j<dp.size(); j++){
            if(result[i] == dp[j][0]) dp2[i].push_back(dp[j][1]);
            else if(result[i] == dp[j][1]) dp2[i].push_back(dp[j][0]);
        }
    }
    if(solve(dp2, result) || nodes.size() == 0) cout<<"True\n";
    else cout<<"False\n";
    return 0;
}