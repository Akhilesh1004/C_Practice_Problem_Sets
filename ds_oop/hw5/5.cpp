#include <iostream> 
#include <vector> 
#include <queue> 
#include <map> 
 
using namespace std; 
 
int find_dis(int x, int y, vector<vector<int>>node, vector<vector<int>>dp, int n){ 
    vector<int>dis(n+1, 99999999); 
    dis[x] = 0; 
    queue<int>q; 
    q.push(x); 
    while(!q.empty()){ 
        int cur = q.front(); 
        q.pop(); 
        for(int i = 0; i<node[cur].size(); i++){ 
            if(dis[node[cur][i]] > dis[cur]+dp[cur][node[cur][i]]){ 
                dis[node[cur][i]] = dis[cur]+dp[cur][node[cur][i]]; 
                q.push(node[cur][i]); 
            } 
        } 
    } 
    return dis[y]; 
} 
 
int main() { 
    int n, m; 
    cin>>n>>m; 
    vector<int>market(n); 
    map<int, int>memo; 
    for(int i = 0; i<n; i++){ 
        cin>>market[i]; 
        memo[market[i]] = 1; 
    } 
    vector<vector<int>>dis(m+1, vector<int>(m+1)); 
    vector<vector<int>>dis2(m+1, vector<int>(m+1, 0)); 
    vector<vector<int>>node(m+1); 
    if(m == 1){
        cout<<"1\n";
        return 0;
    }
    int x, y, z;
    while(cin>>x>>y>>z){  
        node[x].push_back(y); 
        node[y].push_back(x); 
        dis[x][y] = z; 
        dis[y][x] = z; 
    } 
    for(int i = 1; i<=m; i++){ 
        for(int j = i+1; j<=m; j++){ 
            int d = find_dis(i, j, node, dis, m); 
            dis2[i][j] = d; 
            dis2[j][i] = d; 
        } 
    } 
    int maxdis = 0;
    for(int i = 1; i<=m; i++){
        for(int j = 0; j<n; j++){
            maxdis = max(dis2[i][market[j]], maxdis);
        }
    }
    //cout<<maxdis<<"\n";
    int index = 0;
    for (int j = 1; j <= m; ++j) { 
        int total = 0;
        for(int k = 1; k<=m; k++){
            int temp = dis2[j][k];
            for(int i = 0; i<n; i++){
                temp = min(dis2[k][market[i]], temp);
            }
            total = max(total, temp);
        }
        //cout<<total<<" "<<j<<"\n";
        if(total < maxdis){
            maxdis = total;
            index = j;
        }
    }
    cout<<index<<"\n";
    return 0; 
}  