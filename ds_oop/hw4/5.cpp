#include <iostream>
#include <vector>

using namespace std;

int number = 0;
int root = 1;

vector<int> solve(vector<vector<int>>dp, vector<int>&node, int x, int parent){
    vector<int>total(2, 0);
    total[0] = node[x];
    total[1] = dp[x].size();
    for(int i = 0; i<dp[x].size(); i++){
        if(dp[x][i] != parent){
            vector<int>temp = solve(dp, node, dp[x][i], x);
            total[0] += temp[0];
            total[1] += temp[1];
        }
    }
    number += abs(total[0]-(total[1]+1));
    return total;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>dp(n+1);
    vector<int>node(n+1);
    for(int i = 0; i<n; i++){
        int u, v, d;
        cin>>u>>v>>d;
        node[u] = v;
        for(int i = 0; i<d; i++){
            int temp;
            cin>>temp;
            dp[u].push_back(temp);
        }
    }
    number = 0;
    root = 1;
    vector<bool>check(n+1, false);
    for(int i = 1; i<=n; i++){
        if(dp[i].size() == 0){
            check[i] = true;
        }
        else{
            for(int j = 0; j<dp[i].size(); j++){
                check[dp[i][j]] = true;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        if(!check[i]){
            root = i;
        }
    }
    //cout<<root<<"\n";
    solve(dp, node, root, -1);
    cout<<number<<"\n";
    return 0;
}