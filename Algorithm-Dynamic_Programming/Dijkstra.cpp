#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct cell {
    int num;
    int dis;
};
struct greater_order{
    bool operator() (const cell &rhs, const cell &lhs){
        return (rhs.dis > lhs.dis);
    }
};

int main(){
    int n, h, m, x, y, v;
    while(cin>>n>>h>>m){
        vector<vector<int>>neighbor(20);
        vector<vector<int>>cost(20);
        for(int i = 0; i<m; i++){
            cin>>x>>y>>v;
            neighbor[x].push_back(y);
            cost[x].push_back(v);
            neighbor[y].push_back(x);
            cost[y].push_back(v);
        }
        vector<int>ans(20, 9e6);
        vector<int>check(20, false);
        ans[n] = 0;
        cell start = {n, 0};
        priority_queue<cell, vector<cell>, greater_order> q;
        q.push(start);
        while(!q.empty()){
            cell current = q.top();
            q.pop();
            if(check[current.num]) continue;
            check[current.num] = true;
            for(int i = 0; i<neighbor[current.num].size(); i++){
                int next = neighbor[current.num][i];
                if(ans[next] > ans[current.num]+cost[current.num][i]){
                    ans[next] = ans[current.num] + cost[current.num][i];
                    cell next_cell = {next, ans[next]};
                    q.push(next_cell);
                }
            }
        }
        if(ans[h] == 9e6) cout<<"no solution"<<endl;
        else cout<<ans[h]<<endl;
    }
    return 0;
}