#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct cell{
    int num;
    long long dis;
};

struct order{
    bool operator() (const cell &r, const cell &h){
        return r.dis>h.dis;
    }
};

int main(){
    int N;
    while(cin>>N){
        for(int i = 1; i<=N; i++){
            int n, m, s, t;
            cin>>n>>m>>s>>t;
            vector<vector<int>>neighbor(n+1);
            vector<vector<int>>cost(n+1);
            for(int j = 0; j<m; j++){
                int x, y, c;
                cin>>x>>y>>c;
                neighbor[x].push_back(y);
                cost[x].push_back(c);
                neighbor[y].push_back(x);
                cost[y].push_back(c);
            }
            priority_queue<cell, vector<cell>, order>q;
            vector<long long>ans(n+1, 9e8);
            vector<int>check(n+1, false);
            cell start = {s, 0};
            ans[s] = 0;
            q.push(start);
            while(!q.empty()){
                cell cur = q.top();
                q.pop();
                if(check[cur.num]) continue;
                check[cur.num] = true;
                for(int k = 0; k<neighbor[cur.num].size(); k++){
                    int next_ = neighbor[cur.num][k];
                    if(ans[next_] > ans[cur.num]+cost[cur.num][k]){
                        ans[next_] = ans[cur.num]+cost[cur.num][k];
                        cell next = {next_, ans[next_]};
                        q.push(next);
                    }
                }
            }
            if(ans[t] == 9e8) cout<<"Case #"<<i<<": "<<"unreachable"<<endl;
            else cout<<"Case #"<<i<<": "<<ans[t]<<endl;
        }
    }
    return 0;
}