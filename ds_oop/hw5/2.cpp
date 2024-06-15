#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char dp[40][40][40];
int check[40][40][40] = {0};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(){
    int L, R, C, x1= -1, y1 = -1, z1 = -1;
    cin>>L>>R>>C;
    for(int i = 0; i<L; i++){
        for(int j = 0; j<R; j++){
            for(int k = 0; k<C; k++){
                cin>>dp[i][j][k];
                if(dp[i][j][k] == 'S'){
                    x1 = i;
                    y1 = j;
                    z1 = k;
                }
            }
        }
    }
    vector<int>start(4);
    start[0] = x1;
    start[1] = y1;
    start[2] = z1;
    start[3] = 0;
    queue<vector<int>>q;
    q.push(start);
    while(!q.empty()){
        vector<int>cur = q.front();
        check[cur[0]][cur[1]][cur[2]] = 1;
        q.pop();
        if(dp[cur[0]][cur[1]][cur[2]] == 'E'){
            cout<<"Escaped in "<<cur[3]<<" minute(s).\n";
            return 0;
        }
        for(int i = 0; i<6; i++){
            if(cur[0]+dx[i] >= L || cur[0]+dx[i] < 0 || cur[1]+dy[i] >= R || cur[1]+dy[i] < 0 || cur[2]+dz[i] >= C || cur[2]+dz[i] < 0) continue;
            if(check[cur[0]+dx[i]][cur[1]+dy[i]][cur[2]+dz[i]] != 0) continue;
            if(dp[cur[0]+dx[i]][cur[1]+dy[i]][cur[2]+dz[i]] == '#') continue;
            vector<int>next(4);
            next[0] = cur[0]+dx[i];
            next[1] = cur[1]+dy[i];
            next[2] = cur[2]+dz[i];
            next[3] = cur[3]+1;
            q.push(next);
        }
    }
    cout<<"Trapped!\n";
    return 0;
}