#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int posx = 0, posy = 0, endx = 0, endy = 0;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        vector<vector<char>> dp(n, vector<char>(m));
        vector<vector<int>> dis(n, vector<int>(m, -1));
        vector<vector<bool>> check(n, vector<bool>(m, false));
        queue<pair<int , int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> dp[i][j];
                if(dp[i][j] == '.') check[i][j] = true;
                else if(dp[i][j] == 'S'){
                    posx = i;
                    posy = j;
                    check[i][j] = true;
                }
                else if(dp[i][j] == 'G'){
                    endx = i;
                    endy = j;
                    check[i][j] = true;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(dp[i][j] == 'v'){
                    int k = i+1;
                    while(k<n && dp[k][j] == '.'){
                        check[k][j] = false;
                        k++;
                    }
                }
                else if(dp[i][j] == '^'){
                    int k = i-1;
                    while(k>-1 && dp[k][j] == '.'){
                        check[k][j] = false;
                        k--;
                    }
                }
                else if(dp[i][j] == '>'){
                    int k = j+1;
                    while(k<m && dp[i][k] == '.'){
                        check[i][k] = false;
                        k++;
                    }
                }
                else if(dp[i][j] == '<'){
                    int k = j-1;
                    while(k>-1 && dp[i][k] == '.'){
                        check[i][k] = false;
                        k--;
                    }
                }
            }
        }
        q.push(make_pair(posx, posy));
        dis[posx][posy] = 0;
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            if(now.first == endx && now.second == endy) break;
            for(int i = 0; i<4; i++){
                int x = now.first + dx[i];
                int y = now.second + dy[i];
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                if(dis[x][y] != -1) continue;
                if(!check[x][y]) continue;
                dis[x][y] = dis[now.first][now.second] + 1;
                q.push(make_pair(x, y));
            }
        }
        printf("%d\n", dis[endx][endy]);
    }
    return 0;
}