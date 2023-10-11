#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0 ,0, 1, -1};

int solve(int sx, int sy, vector<vector<char>>&grid, bool reached){
    int x, y, ex, ey;
    vector<vector<bool>>visited(n+1, vector<bool>(m+1, false));
    vector<vector<int>>dis(n+1, vector<int>(m+1, -1));
    queue<pair<int, int>>q;
    q.push(make_pair(sx, sy));
    dis[sx][sy] = 0;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(grid[now.first][now.second] == 'E'){
            reached = true;
            ex = now.first;
            ey = now.second;
            break;
        }
        for(int i = 0; i<4; i++){
            x = now.first + dx[i];
            y = now.second + dy[i];
            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(visited[x][y] || grid[x][y] == '#') continue;
            if(dis[x][y] != -1) continue;
            q.push(make_pair(x, y));
            visited[x][y] = true;
            dis[x][y] = dis[now.first][now.second] + 1;
        }
    }
    return dis[ex][ey];
}

int main(){
    int sx, sy;
    bool reached = false;
    while(cin>>n>>m){
        vector<vector<char>>grid(n+5, vector<char>(m+5));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>grid[i][j];
                if(grid[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
            }
        }
        int result = solve(sx, sy, grid, reached);
        cout<<result<<endl;
    }
    return 0;
}