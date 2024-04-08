#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n;

void dfs(vector<vector<int>>&dp, int x, int y){
    dp[x][y] = 0;
    for(int i = 0 ;i<4; i++){
        if(x+dx[i] < 0 || x+dx[i] >= m || y+dy[i] < 0 || y+dy[i] >= n) continue;
        if(dp[x+dx[i]][y+dy[i]] == 1) dfs(dp, x+dx[i], y+dy[i]);
    }
}

int main(){
    cin>>m>>n;
    vector<vector<int>>dp(m, vector<int>(n));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>dp[i][j];
        }
    }
    int result = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(dp[i][j] == 1){
                result++;
                dfs(dp, i, j);
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}