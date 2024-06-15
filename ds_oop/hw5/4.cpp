#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin>>n;
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    vector<vector<int>>node(n+1);
    vector<bool>check(n+1, false);
    for(int i = 1; i<=n; i++){
        cin>>m;
        while(m--){
            int s, t;
            cin>>s>>t;
            node[i].push_back(s);
            dp[i][s] = t;
        }
    }
    int x, y;
    cin>>x>>y;
    vector<int>dis(n+1, 99999999);
    vector<int>parent(n+1, -1);
    dis[x] = 0;
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i<node[cur].size(); i++){
            if(dis[node[cur][i]] > dis[cur]+dp[cur][node[cur][i]]){
                dis[node[cur][i]] = dis[cur]+dp[cur][node[cur][i]];
                parent[node[cur][i]] = cur;
                q.push(node[cur][i]);
            }
        }
    }
    vector<int>path;
    int cur = y;
    while(cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    cout<<"Path =";
    for(int i = path.size()-1; i>=0; i--){
        cout<<" "<<path[i];
    }
    cout<<"; "<<dis[y]<<" second delay\n";
    return 0;
}